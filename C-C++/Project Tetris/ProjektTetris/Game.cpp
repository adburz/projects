#include "Game.h"

Game::Game()
{
	this->menuF();
}
Game::~Game()
{
	delete this->menu;
	delete this->board;
	delete this->tet;
	delete this;
}

void Game::menuF()
{
	sf::RenderWindow window(sf::VideoMode(600, 300), "Tetris Game");
	sf::SoundBuffer buff; sf::Sound sound;
	if (!buff.loadFromFile("music/menu-navigate.wav")) std::cout << "\nCAN'T OPEN MENU_NAVIGATE SOUND\n";
	else {
		sound.setBuffer(buff);
		sound.setVolume(7);
	}
	float x = window.getSize().x;
	float y = window.getSize().y;
	this->menu = new Menu{  x, y};
	while (window.isOpen())
	{
		sf::Event eve;
		while (window.pollEvent(eve))
		{
			if (eve.type == sf::Event::Closed)
				window.close();
			else if (eve.type == sf::Event::KeyPressed)
			{

				if (eve.key.code == sf::Keyboard::Up) { if (this->menu->sounds)sound.play(); this->menu->up(); }
				else if (eve.key.code == sf::Keyboard::Down) { if (this->menu->sounds)sound.play(); this->menu->down(); }
				else if (eve.key.code == sf::Keyboard::Enter)
				{
					if (this->menu->sounds)sound.play();
					int result = this->menu->mechanism();
					if (result == 0) { window.clear(); window.close(); this->game(); }
					else if (result == 1) this->menu->credits(window, sound);
					else if (result == 2) { this->quit(window); return; }
					else continue;
				}
				else if (eve.key.code == sf::Keyboard::S) { if (this->menu->sounds)sound.play(); this->menu->switchSounds(); }
				else if (eve.key.code == sf::Keyboard::M) { if (this->menu->sounds)sound.play(); this->menu->switchMusic(); }
			}
		}
		window.clear();
		this->menu->print(window);
		window.display();
	}
}

void Game::quit(sf::RenderWindow& window)
{
	window.clear();
	window.close();
	delete this->board;
	delete this->tet;
}

void Game::endGame(sf::RenderWindow& window)
{
	sf::Text gameOver, tutor;
	gameOver.setFont(this->menu->font);
	tutor.setFont(this->menu->font);
	gameOver.setString("GAME OVER!");
	tutor.setString("To get back into main menu, \npress enter.");
	gameOver.setCharacterSize(20);
	tutor.setCharacterSize(10);
	//gameOver.setColor(sf::Color::Red);
	gameOver.setPosition(window.getSize().x / 4, window.getSize().y / 3);
	tutor.setPosition(window.getSize().x / 4 -45, window.getSize().y / 3 + 20);
	window.draw(gameOver);
	window.draw(tutor);
	window.display();
	while (window.isOpen())
	{
		sf::Event e;
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				window.close();
			else if (e.type == sf::Event::KeyPressed)
			{
				if (e.key.code == sf::Keyboard::Enter)
					return;
			}
		}
	}
}

void Game::game()
{
	sf::Music music;
	sf::SoundBuffer sBuffer1, sBuffer2, sBuffer3, sBuffer4;
	sf::Sound explosion1, explosion3, explosion4, death;
	if (this->menu->music)
	{
		if (!music.openFromFile("music/Tetris_theme.ogg")) {
			std::cout << "\nCAN'T OPEN MUSIC FILE\n";
		}
		else music.setVolume(10);
	}
	if (this->menu->sounds)
	{
		if (!sBuffer1.loadFromFile("music/explosion_1.wav")) std::cout << "\nCAN'T OPEN explosion_1.wav FILE\n";
		else {
			explosion1.setBuffer(sBuffer1);
			explosion1.setVolume(10);
		}
		if (!sBuffer2.loadFromFile("music/explosion_3.wav")) std::cout << "\nCAN'T OPEN explosion_3.wav FILE\n";
		else {
			explosion3.setBuffer(sBuffer2);
			explosion3.setVolume(10);
		}
		if (!sBuffer3.loadFromFile("music/explosion_4.wav")) std::cout << "\nCAN'T OPEN explosion_4.wav FILE\n";
		else {
			explosion4.setBuffer(sBuffer3);
			explosion4.setVolume(10);
		}
		if (!sBuffer4.loadFromFile("music/death.wav")) std::cout << "\nCAN'T OPEN death.wav FILE\n";
		else {
			death.setBuffer(sBuffer4);
			death.setVolume(10);
		}
	}
	srand(time(NULL));
	this->points = 0;
	int dx = 0;
	float timer = 0, delay = 0.3, time;
	bool rotate = false;
	if (this->menu->music) { music.play(); music.setLoop(true); }
	sf::RenderWindow window(sf::VideoMode(320, 480), "TETRIS");
	sf::Event event;
	sf::Clock clock;
	Board* field = new Board{};
	Tet* tmpTet;

	//konstrktory spriteow
	sf::Texture tex, background; tex.loadFromFile("images/texture.png"); background.loadFromFile("images/background4.png");
	sf::Sprite sprBlue(tex, sf::IntRect(0, 0, 18, 18));
	sf::Sprite sprRed(tex, sf::IntRect(18, 0, 18, 18));
	sf::Sprite sprGreen(tex, sf::IntRect(36, 0, 18, 18));
	sf::Sprite sprYellow(tex, sf::IntRect(54, 0, 18, 18));
	sf::Sprite bckg(background);

	while (window.isOpen()) {
		//losowanie ksztaltu
		int objectType = rand() % 7 + 1;
		if (objectType == 1)		tmpTet = new D_type{};//D type
		else if (objectType == 2)		tmpTet = new L_type{};//L type
		else if (objectType == 3)	tmpTet = new rL_type{};//rL type
		else if (objectType == 4)	tmpTet = new I_type{};//I type
		else if (objectType == 5)	tmpTet = new Z_type{};//Z type	
		else if (objectType == 6)	tmpTet = new S_type{};//S type	
		else						tmpTet = new T_type{};//T type
		randomColour(tmpTet->colour);
		field->tmpTetris = tmpTet;
		//todo ustawianie poczatkowej lokazliacji
		field->cx = 4; field->cy = 0;
		if (field->canSpawn()) {
			for (int i = 0; i <= tmpTet->y_max; i++) {
				for (int j = 0; j <= tmpTet->x_max; j++) {
					if (tmpTet->array[i][j] == true) {
						field->board[i][j + 4] = tmpTet->colour;
					}
				}
			}
			//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			while (field->tmpTetris->canFall(field->board, field->cx, field->cy)) {
				time = clock.getElapsedTime().asSeconds();
				clock.restart();
				timer += time;
				while (window.pollEvent(event)) {
					if (event.type == sf::Event::Closed)
						window.close();
					else if (event.type == sf::Event::KeyPressed)
					{
						if (event.key.code == sf::Keyboard::Left) dx = -1;
						else if (event.key.code == sf::Keyboard::Right) dx = 1;
						else if (event.key.code == sf::Keyboard::Up) rotate = true;
						else if (event.key.code == sf::Keyboard::Down)  delay = 0.07;
					}
				}
				//! MOVE
				if (dx != 0)
					field->move(dx);
				if (rotate)
					tmpTet->rotate(*field);
				//! T I C K
				if (timer > delay)
				{
					field->tmpTetris->fallingMove(*field);
					timer = 0;
				}
				dx = 0; delay = 0.5; rotate = false;
				window.clear();
				field->points(window, this->menu->font, this->points);
				field->printIt(window, bckg, sprRed, sprGreen, sprBlue, sprYellow);
				window.display();
				if (field->tmpTetris->canFall(field->board, field->cx, field->cy)) continue;
				else field->endingMove(window, bckg, clock, event, sprRed, sprGreen, sprBlue, sprYellow, this->menu->font, this->points);
				//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			}
			field->ifLine(explosion1, explosion3, explosion4, this->menu->sounds, this->points);
			delete tmpTet;
		}
		else {
			window.clear(sf::Color::Black);
			music.stop();
			death.play();
			this->endGame(window);
			this->quit(window);
			this->menuF();
		}
	}
}
void Game::randomColour(int& colour)
{
	colour = rand() % 4 + 1;
}
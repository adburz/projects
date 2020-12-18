#include "Menu.h"

#pragma warning(disable : 4996)
#define PLAY 0
#define CREDITS 1
#define QUIT 2

Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("fonts/Xenotron.ttf"))
		std::cout << "Can't open fonts/Xenotron.ttf font. Find and load your font again";

	for (int i = 0; i < MENU; i++)
	{
		menu[i].setFont(this->font);
		menu[i].setColor(sf::Color::White);
		menu[i].setPosition(sf::Vector2f(width / 3 +30 , 30 + height / (MENU + 1) * i));
	}
	menu[0].setString("PLAY");
	menu[0].setStyle(sf::Text::Underlined | sf::Text::Bold);
	menu[1].setString("CREDITS");
	menu[2].setString("QUIT");
	selectedId = 0;

	music = true; sounds = true;
	for (int j = 0; j < OPTIONS; j++){
		options[j].setFont(this->font);
		if(j%2 == 1)options[j].setColor(sf::Color::Green);
		else options[j].setColor(sf::Color(192, 192, 192));
		if (j % 2 == 1) options[j].setString(" On");
		if(j%2==0)options[j].setPosition(sf::Vector2f(0, height - 15 -15 * (!j ? 0:1)));
		options[j].setCharacterSize(15);
	}
	options[0].setString("MUSIC:");
	options[2].setString("SOUNDS:");
	options[MUSIC].setPosition(sf::Vector2f(options[0].getLocalBounds().width, height - 15));
	options[SOUNDS].setPosition(sf::Vector2f(options[2].getLocalBounds().width, height - 30));
	tutor.setFont(font);
	tutor.setColor(sf::Color::Yellow);
	tutor.setCharacterSize(10);
	tutor.setString("Click M/S to \nchange state");
	tutor.setStyle(sf::Text::Underlined);
	tutor.setPosition(sf::Vector2f(0, height - 55));
}
Menu::~Menu()
{
}

void Menu::print(sf::RenderWindow& window)
{
	if (this->scene && window.isOpen()) {
		for (int i = 0; i < MENU; i++)
			window.draw(menu[i]);
		for (int j = 0; j < OPTIONS; j++)
			window.draw(options[j]);
		window.draw(tutor);
	}
}

void Menu::up()
{
	if (selectedId - 1 >= 0)
	{
		menu[selectedId].setStyle(NULL);
		selectedId--;
		menu[selectedId].setStyle(sf::Text::Underlined | sf::Text::Bold);
	}
}
void Menu::down()
{
	if (selectedId + 1 < MENU)
	{
		menu[selectedId].setStyle(NULL);
		selectedId++;
		menu[selectedId].setStyle(sf::Text::Underlined | sf::Text::Bold);
	}
}

int Menu::mechanism()
{
	switch (this->getMenuState())
	{
	case PLAY: 
		return 0;
		break;
	case CREDITS:
		return 1;
		break;
	case QUIT: return 2;
	default: return 2;
	}
}

int Menu::getMenuState()
{
	return selectedId;
}

void Menu::switchMusic()
{
	if (music) {
		options[MUSIC].setColor(sf::Color::Red); 
		options[MUSIC].setString(" OFF");
		music = false;
	}
	else {
		options[MUSIC].setColor(sf::Color::Green);
		options[MUSIC].setString(" ON");
		music = true;
	}
}
void Menu::switchSounds()
{
	if (sounds) {
		options[SOUNDS].setColor(sf::Color::Red); 
		options[SOUNDS].setString(" OFF");
		sounds = false;
	}
	else {
		options[SOUNDS].setColor(sf::Color::Green); 
		options[SOUNDS].setString(" ON");
		sounds = true;
	}
}

void Menu::credits(sf::RenderWindow& window, sf::Sound &sound)
{
	this->scene = false;
	sf::Text tut, credits;
	tut.setFont(font); credits.setFont(font);
	tut.setCharacterSize(13); credits.setCharacterSize(21);
	tut.setColor(sf::Color::White); credits.setColor(sf::Color(192,192,192));
	tut.setString("To get back, click BACKSPACE");
	tut.setStyle(sf::Text::Underlined);
	tut.setPosition(0, 0);
	credits.setPosition(10, 100);
	credits.setString("Programmer:  Adam Burzynski\n\n\nMusic:  Bogozi\n\n\nSounds:  LittleRobotSoundFactory");

	while (window.isOpen())
	{
		sf::Event e;
		while (window.pollEvent(e))
		{
			
			if (e.type == sf::Event::Closed)
				window.close();
			else if (e.type == sf::Event::KeyPressed)
			{
				if (this->sounds)sound.play();
				if (e.key.code == sf::Keyboard::BackSpace) 
				{
					this->scene = true;
					return;
				
				}
			}
		}
		window.clear();
		window.draw(tut);
		window.draw(credits);
		window.display();
	}


}
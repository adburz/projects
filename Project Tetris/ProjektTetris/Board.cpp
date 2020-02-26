#pragma once
#include "Board.h"


void Board::printIt(sf::RenderWindow& w, sf::Sprite &bckg, sf::Sprite& red, sf::Sprite& green, sf::Sprite& blue, sf::Sprite& yellow)
{
	w.draw(bckg);
	for (int i = 0; i < Wer; i++)
	{
		for (int j = 0; j < Col; j++)
		{	//0-puste, 1- czerwony, 2- zielony, 3-niebieski, 4-zolty 
			if (this->board[i][j] == 1) {
				red.setPosition(j * 18+10, i * 18 + 10);
				w.draw(red);
			}
			else if (this->board[i][j] == 2) {
				green.setPosition(j * 18 + 10, i * 18 + 10);
				w.draw(green);
			}
			else if (this->board[i][j] == 3) {
				blue.setPosition(j * 18 + 10, i * 18 + 10);
				w.draw(blue);
			}
			else if (this->board[i][j] == 4) {
				yellow.setPosition(j * 18 + 10, i * 18 + 10);
				w.draw(yellow);
			}
			else continue;
		}
	}
}
void Board::points(sf::RenderWindow& w, sf::Font &font, int &points)
{
	std::string sPoints = std::to_string(points);
	sf::Text t, p;
	t.setFont(font);					p.setFont(font);
	t.setCharacterSize(18);				p.setCharacterSize(18);
	t.setString("Your points:   ");		p.setString(sPoints);
	t.setPosition(sf::Vector2f(0, 420));p.setPosition(sf::Vector2f(t.getGlobalBounds().width, 420));
	w.draw(t); w.draw(p);
}

void Board::move(int direction)
{
	if (direction == 1) {
		if (canMoveRight())
			this->tmpTetris->moveRight(*this);
	}
	else if (direction == -1)
		if (canMoveLeft())
			this->tmpTetris->moveLeft(*this);
}
bool Board::canMoveLeft()
{
	if (cx != EXTREME_LOW_X && this->tmpTetris->canMoveLeft(this->board, this->cx, this->cy))
		return true;
	else
		return false;
}
bool Board::canMoveRight()
{
	if ((cx < EXTREME_HIGH_X) && (this->tmpTetris->canMoveRight(this->board, this->cx, this->cy)))
		return true;
	else
		return false;
}

void Board::update(int colour)
{
	if (this->tmpTetris)
	{
		for (int i = 0; i <= this->tmpTetris->y_max; i++)
			for (int j = 0; j <= tmpTetris->x_max; j++)
				if (tmpTetris->array[i][j] == true)
					this->board[i + this->cy][j + this->cx] = colour;


	}

}
void Board::clearTetris()
{
	for (int i = 0; i <= this->tmpTetris->y_max; i++)
		for (int j = 0; j <= tmpTetris->x_max; j++)
		{
			if (this->tmpTetris->array[i][j] == true)
			{
				std::cout << i << "      " << j << std::endl;
				this->board[i + this->cy][j + this->cx] = 0;
			}
		}

}

void Board::breakTheLine(int werse)
{
	int last_x, last_y, colour;

	for (int i = 0; i < 10; i++)
		this->board[werse][i] = 0;

	for (int i = werse - 1; i >= 0; i--)
	{
		for (int j = 0; j < 10; j++)
		{
			if (this->board[i][j] != 0)
			{
				colour = this->board[i][j]; last_x = j; last_y = i;
				this->board[i + 1][j] = colour;
				this->board[last_y][last_x] = 0;
			}
			else continue;
		}

	}
}

void Board::ifLine(sf::Sound &explosion1, sf::Sound &explosion3, sf::Sound &explosion4, bool ifSound, int &points)
{
	int been = 0, howMany=0;
	for (int i = 19; i >= 0; i--)
	{
		for (int j = 0; j < 10; j++) {
			if (this->board[i][j] != 0)
				been++;
			if (been == 0) break;
		}
		if (been == 10) { breakTheLine(i); i++; howMany++; }
		been = 0; 
	}
	if (ifSound) {
		if (howMany == 1 || howMany == 2) explosion1.play();
		else if (howMany == 3) explosion3.play();
		else if (howMany == 4) explosion4.play();
	}
	points += howMany * 10 + ((howMany == 4) * 200);
	howMany = 0;
}

void Board::endingMove(sf::RenderWindow &window, sf::Sprite& bckg, sf::Clock &clock, sf::Event event, sf::Sprite& red, sf::Sprite& green, sf::Sprite& blue, sf::Sprite& yellow, sf::Font& font, int& points)
{
	float start = 0, end = 0.5, time;
	while (start < end) {
		time = clock.getElapsedTime().asSeconds();
		clock.restart();
		start += time;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Left) this->move(-1);
				else if (event.key.code == sf::Keyboard::Right)	this->move(1);
				
			}
			window.clear();
			this->printIt(window,bckg, red, green, blue, yellow);
			this->points(window, font, points);
			window.display();
		}
	}
	
}

bool Board::canSpawn()
{
	for (int i = 0; i <= this->tmpTetris->y_max; i++)
		for (int j = 0; j <= tmpTetris->x_max; j++)
		{
			if (this->tmpTetris->array[i][j] == true)
			{
				if (this->board[i + this->cy][j + this->cx] != 0)
					return false;
			}
		}
	return true;
}
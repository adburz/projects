#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include <iostream>
#include "Tet.h"
#include "ConstantVar.h"



#define EXTREME_LOW_X 0
#define EXTREME_HIGH_X 9


class Tet;
class Board
{
	friend class Game;
	bool canMoveLeft();
	bool canMoveRight();
public:
	int board[Wer][Col];				//0-puste, 1- czerwony, 2- zielony, 3-niebieski, 4-zolty 
												//?(tym sposobem, mozna by losowac jakies randomowe problemy, wrzucajac w konstruktor tryb gry)
	Tet* tmpTetris;								//zeby wiedziec jaki aktualnie obslugujemy rodzaj klocka do funckji canMoveL/R
	int cx=0, cy = 0;
	void move(int direction);
	void update(int colour);
	void clearTetris();
	void breakTheLine(int werse);
	void ifLine(sf::Sound &explosion1, sf::Sound &explosion3, sf::Sound &explosion4, bool ifSound, int &points);
	bool canSpawn();
	void endingMove(sf::RenderWindow& window, sf::Sprite& bckg, sf::Clock& clock, sf::Event event, sf::Sprite& red, sf::Sprite& green, sf::Sprite& blue, sf::Sprite& yellow, sf::Font& font, int& points);
	Board() {
		for (int i = 0; i < Wer; i++)
			for (int j = 0; j < Col; j++)
				this->board[j][i] = 0;
	};
	void printIt(sf::RenderWindow& w, sf::Sprite& bckg, sf::Sprite& red, sf::Sprite& green, sf::Sprite& blue, sf::Sprite& yellow);
	void points(sf::RenderWindow& w, sf::Font &font, int &points);
};

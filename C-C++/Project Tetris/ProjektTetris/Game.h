#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include <iostream>
#include "Menu.h"
#include "Board.h"
#include "Tet.h"
#include "Tet_D.h"
#include "Tet_I.h"
#include "Tet_L.h"
#include "Tet_rL.h"
#include "Tet_S.h"
#include "Tet_T.h"
#include "Tet_Z.h"

class Menu;
class Tet;
class Board;
class Game
{
public:
	Game();
	~Game();
	void game();
	void menuF();
	void quit(sf::RenderWindow& window);
	void endGame(sf::RenderWindow& window);
	int points;
private:
	Menu* menu;
	Board* board;
	Tet* tet;

	void randomColour(int& colour);
};
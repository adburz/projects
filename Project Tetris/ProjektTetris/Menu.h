#pragma once
#include <SFML/Graphics.hpp>
#include "SFML/Audio.hpp"
#include "iostream"
#define MENU 3
#define OPTIONS 4
#define MUSIC 1
#define SOUNDS 3


class Menu
{
	friend class Game;
	Menu(float width, float height);
	~Menu();

	void print(sf::RenderWindow& window);
	void up();
	void down();
	int mechanism();
	int getMenuState();
	void switchMusic();
	void switchSounds();
	void credits(sf::RenderWindow& window, sf::Sound &sound);
protected:
	bool scene;
	int selectedId;
	bool music;
	bool sounds;
	sf::Font font;
	sf::Text tutor;
	sf::Text menu[MENU];
	sf::Text options[OPTIONS];
};
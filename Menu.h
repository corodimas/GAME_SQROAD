#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#define MAX_ITEM 3

class Menu
{
public:
	Menu();
	~Menu();
	void Moveup();
	void Movedown();
	int GetPressedItem() { return selecteditem; }
	
	void rendermenu(sf::RenderTarget& target);
	void menuupdate();

	void renderleaderboard(sf::RenderTarget& target);

	void rendergameoverscene(sf::RenderTarget& target);

	sf::RectangleShape selector;


	sf::Texture  titletexture;
	sf::Sprite titlesprite;

	sf::Texture leaderboardtexture;
	sf::Sprite leaderboardsprite;

	sf::Texture gameovertexture;
	sf::Sprite gameoversprite;


	int x;
	int y;

private:
	void initmenu();
	void intiselector();
	void initsprite();

	int selecteditem = 0;
	sf::Font font;
	sf::Text menu[MAX_ITEM];

	

};


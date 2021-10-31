#pragma once
#include"Player.h"
#include"Background.h"	
#include"Game.h"
#include"Enemy.h"
#include "View.h"

#include<SFML/Graphics.hpp>


class Game
{
private:
	sf::RenderWindow* window;
	sf::Event ev;
	sf::View playerview;


	Player* player;
	Background* world;
	Enemy* enemy;
	View* view;


	//PRIVATE FUNCTION
	void intitwindow();
	void initplayer();
	void initworld();
	void initenemy();
	void initview();

public:
	Game();
	virtual ~Game();
	

	//Function

	void running();
	void render();
	void update();
};


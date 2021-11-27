#pragma once
#include"Player.h"
#include"Background.h"	
#include"Game.h"
#include"Enemy.h"
#include "View.h"
#include "Score.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include<map>
#include<string>
#include<sstream>
#include<SFML/Graphics.hpp>
#include "Menu.h"
#include "Leaderboard.h"
#include "Item.h"


class Game :public Player, public Enemy, public View, public Background, public Menu
{
private:
	sf::RenderWindow* window;
	sf::Event ev;
	sf::View playerview;


	Player* player;
	Background* world;
	Enemy* enemy;
	View* view;
	Score* score;
	Menu* menu;
	Item* item;

	sf::Font font;
	sf::Text text;

	std::string name;

	int point;

	bool gameover =false ;
	bool menustate =true ;
	bool leaderboardstate =false ;
	bool gamestate =false ;

	bool playerstatus = false;


	//PRIVATE FUNCTION
	void intitwindow();
	void initplayer();
	void initworld();
	void initenemy();
	void initview();
	void initscore();
	void initmenu();
	void initItem();

	void updatePollEvent();

public:
	Game();
	virtual ~Game();
	

	//Function
	void GUIrender();
	void running();
	void render();
	void update();

	void gamereset();
};


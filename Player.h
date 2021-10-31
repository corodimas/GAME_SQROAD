#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>


class Player
{
public:
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Vector2u imagecount;
	sf::Vector2u currentimage;
	sf::Clock playerClock;
	
	


	

private:

	void inittexture();
	void initsprite();

public:
	int tilesize = 50;
	float x;
	float y;
	float movespeed;
	enum MOVE { UP, DOWN, LEFT, RIGHT };
	bool move[4];
	bool walking;
	int nextspot;
	int animationFrame = 0;
	int spriteSizex;
	int spriteSizey;
	float deltatime = 50.0f;


public:
	Player();
	virtual ~Player();	
	void collision();
	
	void keymove();
	void moving();
	void update();
	void render(sf::RenderTarget& target);

	float getx();
	float gety();

};


#include "Background.h"

#include<iostream>

void Background::inittexture()
{
	if (!map.loadFromFile("image/Background/WORD1_real.png"))
		std::cout << "Can not load Background";
	if (!map2.loadFromFile("image/Background/WORLD3_REAL.png"))
		std::cout << "Can not load Background";
	if (!map3.loadFromFile("image/Background/WORLD4_REAL.png"))
		std::cout << "Can not load Background";
	if (!map4.loadFromFile("image/Background/WORLD2_REAL.png"))
		std::cout << "Can not load Background";
}

void Background::initsprite()
{
	this->mapsprite[0].setTexture(this->map);
	this->mapsprite[1].setTexture(this->map2);
	this->mapsprite[2].setTexture(this->map3);
	this->mapsprite[3].setTexture(this->map4);
	this->mapsprite[4].setTexture(this->map);
	this->mapsprite[5].setTexture(this->map2);
	this->mapsprite[6].setTexture(this->map3);
	this->mapsprite[7].setTexture(this->map4);

	this->mapsprite[j].setPosition(0, -1000);
	this->mapsprite[l].setPosition(0, -1000);
}

	

void Background::renderworld(sf::RenderTarget& target)
{

		target.draw(this->mapsprite[i]);
		target.draw(this->mapsprite[j]);
		target.draw(this->mapsprite[l]);
	
}

void Background::seemlessbackground(float& camerapos, float& playposy, bool& walking)
{

	if (playposy== -100)
	{
		playposy = 900;
		camerapos = 500;
		i = j;
		j += 1;
		j %= 4;
		walking = false;
		changeBG = true;

		this->mapsprite[i].setPosition(0, 0);
		this->mapsprite[j].setPosition(0, -1000);
	}
	if (changeBG == true)
	{
		if (bgt > 10)
		{
			l = j+4;
			changeBG = false;
			bgt = 0;
			this->mapsprite[l].setPosition(0, -1000);
		}
		bgt++;
		
	}
}

void Background::riverflow()
{
}



Background::Background()
{
	this->inittexture();
	this->initsprite();
}

Background::~Background()
{
}

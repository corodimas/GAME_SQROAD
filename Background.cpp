#include "Background.h"

#include<iostream>

void Background::inittexture()
{
	if (!map.loadFromFile("image/Background/WORLD1_3.png"))
		std::cout << "Can not load Background";
	this->mapsprite.setTexture(this->map);
}

void Background::renderworld(sf::RenderTarget& target)
{
	target.draw(this->mapsprite);
}

void Background::riverflow()
{
}

Background::Background()
{
	this->inittexture();
}

Background::~Background()
{
}

#include "Player.h"
#include"Game.h"
#include"ENEMy.h"
#include<iostream>


Enemy carblue;

Player::Player()
{
	this->inittexture();
	this->initsprite();
	x = 350;
	y = 950;
	currentdistance = 0;

	movespeed = 5.0;

	for (int i = 0; i < 4; ++i)
	{
		move[i] = false;
	}
	walking = false;
	this->initshape();
}
Player::~Player()
{
}



void Player::keymove()
{
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (walking == false)
		{
			nextspot = y - tilesize;
			move[UP] = true;
			walking = true;
		}
		

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)&& y<950)
	{
		if (walking == false)
		{
			nextspot = y + tilesize;
			move[DOWN] = true;
			walking = true;
		}
		
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)&&x>0)
	{
		if (walking == false)
		{
			nextspot = x - tilesize;
			move[LEFT] = true;
			walking = true;
		}
		
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)&&x<750)
	{
		if (walking == false)
		{
			nextspot = x + tilesize;
			move[RIGHT] = true;
			walking = true;
		}
		
	}
}

void Player::moving()
{
	if (walking == true)
	{
		if (move[UP] == true)
		{
			y -= movespeed;
			currentdistance++;
			if (y <= nextspot)
			{
				walking = false;
				move[UP] = false;
			}
			this->sprite.setTextureRect(sf::IntRect(spriteSizex * animationFrame, spriteSizey * 3, spriteSizex, spriteSizey));

		}
		if (move[DOWN] == true)
		{
			y += movespeed;
			currentdistance--;
			if (y >= nextspot)
			{
				walking = false;
				move[DOWN] = false;
			}
			this->sprite.setTextureRect(sf::IntRect(spriteSizex * animationFrame, 0, spriteSizex, spriteSizey));
		}
		if (move[LEFT] == true)
		{
			x -= movespeed;
			if (x <= nextspot)
			{
				walking = false;
				move[LEFT] = false;
			}
			this->sprite.setTextureRect(sf::IntRect(spriteSizex * animationFrame, spriteSizey * 1, spriteSizex, spriteSizey));
			
		}
		if (move[RIGHT] == true)
		{
			x += movespeed;
			if (x >= nextspot)
			{
				walking = false;
				move[RIGHT] = false;
			}
			this->sprite.setTextureRect(sf::IntRect(spriteSizex * animationFrame, spriteSizey * 2, spriteSizex, spriteSizey));
		}
	}
}






void Player::inittexture()
{
	this->texture.loadFromFile("image/char/Squrrial.png");
	spriteSizex = texture.getSize().x / 3;
	spriteSizey = texture.getSize().y / 4;
}

void Player::initsprite()
{
	this->sprite.setScale(sf::Vector2f(1, 1));
	this->sprite.setTexture(texture);
	this->sprite.setTextureRect(sf::IntRect(spriteSizex * animationFrame, spriteSizey * 3, spriteSizex, spriteSizey));
}

void Player::initshape()
{
	hitbox.setSize(sf::Vector2f(20.0f,20.0f));
	hitbox.setPosition(x, y);
}


void Player::update()
{
	if (playerClock.getElapsedTime().asMilliseconds() > deltatime)
	{
		animationFrame++;
		if (animationFrame >= 2)
		{
			animationFrame = 0;
		}
		playerClock.restart();
	}
	keymove();
	moving();

	sprite.setPosition(x, y);
	hitbox.setPosition(x+20, y+25);

}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}

float Player::getx()
{
	return sprite.getPosition().x;
}



float Player::gety()
{
	return sprite.getPosition().y;
}

int Player::distance()
{
	maxdistance = currentdistance;
	return maxdistance;

}


















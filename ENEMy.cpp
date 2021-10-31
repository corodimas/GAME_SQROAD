#include "ENEMy.h"
#include "Player.h"
#include <ctime>
#include<iostream>


void Enemy::inittexture()
{
	if(!car1Texture.loadFromFile("image/vehicles/medium/CarBluev2.png"))
		std::cout<< "Can not load CarBlue Texture";
}

void Enemy::initsprite()
{
	this->car1Sprite.setTexture(car1Texture);
}



Enemy::Enemy()
{
	this->inittexture();
	this->initsprite();
	this->x = -100.0f;
	this->y = 50.0f;
	this->points = 0;
	this->enemySpawnTimer = this->enemySpawnTimemax;
	this->enemySpawnTimemax = 100.f;
	this->maxEnemies = 10;
	std::srand(static_cast<unsigned>(time(NULL)));
}

Enemy::~Enemy()
{
}

void Enemy::enemyupdate()
{
	
	if (this->BLuecars.size() < this->maxEnemies)
		if (this->enemySpawnTimer >= this->enemySpawnTimemax)
		{
			this->spawnenemy();
			this->enemySpawnTimer = 0.f;
		}
		else
			this->enemySpawnTimer += 1.f;
	
	for (auto& BC : this->BLuecars)
	{
		BC.move(5.f, 0.f);

		if (BC.getPosition().x > 1000)
		{
			int index = rand() % Bluecarpos.size();
			BC.setPosition(
				-200,
				Bluecarpos[index]
			);
		}

	}
}

void Enemy::spawnenemy()
{
	int index = rand() % Bluecarpos.size();
	this->car1Sprite.setPosition(
		-200,
		Bluecarpos[index]
	);

	this->BLuecars.push_back(this->car1Sprite);
}

void Enemy::enemyrender(sf::RenderTarget& target)
{
	for (auto& BC : this->BLuecars)
	{
		target.draw(BC);
	}
		
}

#include "ENEMy.h"
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
	this->enemySpawnTimemax = 0.f;
	this->maxEnemies = 10;

	SpawnTime = 50;
	std::srand(static_cast<unsigned>(time(NULL)));
	carrun.loadFromFile("Death.wav");
	carrunsound.setBuffer(carrun);
	carrunsound.setVolume(10);
	carspeed.x = 5.0f;
	carspeed.y = 0.0f;
	currenttime = 0;
	
	

}

Enemy::~Enemy()
{
}

void Enemy::enemyupdate(sf::FloatRect playerbound,float &x,float&y,bool &moving ,int &map1, int& map2, int& map3,bool& gameover,bool &playstatus,int &score,bool &itempicked,sf::Sprite map[])
{
	
	if (this->BLuecars.size() < this->maxEnemies)
		if (this->enemySpawnTimer >= this->enemySpawnTimemax)
		{
			this->spawnenemy(map1);
			this->enemySpawnTimer = 0.f;
			this->enemySpawnTimemax = SpawnTime;
		}
		else
			this->enemySpawnTimer += 1.f;
	
	for (int i =0;i<BLuecars.size();i++)
	{
		if (carstop == false)
		{
			BLuecars[i].move(carspeed);
		}
		if (BLuecars[i].getPosition().x > 1000)
		{
			switch (map1+1)
			{
			case 1:
			{
				int index = rand() % Bluecarpos.size();
				BLuecars.erase(this->BLuecars.begin() + i);
				//this->car1Sprite.setPosition(-200, Bluecarpos[index]);
				//this->BLuecars.push_back(this->car1Sprite);
				//BLuecars[i].setPosition(-200, Bluecarpos[index]);
				break;

			}
			case 2:
			{
				int index = rand() % Bluecarpos2.size();
				BLuecars.erase(this->BLuecars.begin() + i);
				//this->car1Sprite.setPosition(-200, Bluecarpos2[index]);
				//this->BLuecars.push_back(this->car1Sprite);
				/*int index2 = rand() % Bluecarpos2.size();
				BLuecars[i].setPosition(-200, Bluecarpos2[index2]);*/
				break;
			}
			case 3:
			{
				int index = rand() % Bluecarpos3.size();
				BLuecars.erase(this->BLuecars.begin() + i);
				//this->car1Sprite.setPosition(-200, Bluecarpos3[index]);
				//this->BLuecars.push_back(this->car1Sprite);
				/*int index3 = rand() % Bluecarpos3.size();
				BLuecars[i].setPosition(-200, Bluecarpos3[index3]);*/
				break;
			}
			case 4:
			{
				int index = rand() % Bluecarpos3.size();
				BLuecars.erase(this->BLuecars.begin() + i);
				//this->car1Sprite.setPosition(-200, Bluecarpos3[index]);
				//this->BLuecars.push_back(this->car1Sprite);
				/*int index = rand() % Bluecarpos4.size();
				BLuecars[i].setPosition(-200, Bluecarpos4[index]);*/
				break;
			}
			}
		}
		if (BLuecars[i].getGlobalBounds().intersects(playerbound))
		{
			moving = false;
			playstatus = true;
			x = 350;
			y = 950;
			map1 = 0;
			map2 = 1;
			map3 = map2 + 4;
			map[map1].setPosition(0, 0);
			map[map2].setPosition(0, -1000);
			map[map3].setPosition(0, -1000);
			BLuecars.clear();
			carrunsound.play();
		}
		
	

	}
	if (map1 != previousmap)
	{
		BLuecars.clear();
	}
	if (itempicked == true)
	{
		currenttime += 1.0f;
		if (currenttime >= itemtime)
		{

			itempicked = false;
			currenttime = 0;
		}
	}
	else
	{
		carspeed.x = 5.0f + score / 1000;
		maxEnemies = 10 + score / 1000;
		SpawnTime = 50 - score / 1000;

	}
	previousmap = map1;
	//std::cout << "MAXenemy: " << maxEnemies << "spawnTime:" << SpawnTime<< "\n";
}

void Enemy::spawnenemy(int map)
{

	switch (map + 1)
	{
	case 1:
	{
		int index = rand() % Bluecarpos.size();
		this->car1Sprite.setPosition(-200, Bluecarpos[index]);
		this->BLuecars.push_back(this->car1Sprite);
		break;

	}
	case 2:
	{
		int index2 = rand() % Bluecarpos2.size();
		this->car1Sprite.setPosition(-200, Bluecarpos2[index2]);
		this->BLuecars.push_back(this->car1Sprite);
		break;
	}
	case 3:
	{
		int index3 = rand() % Bluecarpos3.size();
		this->car1Sprite.setPosition(-200, Bluecarpos3[index3]);
		this->BLuecars.push_back(this->car1Sprite);
		break;
	}
	case 4:
	{
		int index = rand() % Bluecarpos4.size();
		this->car1Sprite.setPosition(-200, Bluecarpos4[index]);
		this->BLuecars.push_back(this->car1Sprite);
		break;
	}
	}
}

void Enemy::enemyrender(sf::RenderTarget& target)
{
	for (auto& BC : this->BLuecars)
	{
		target.draw(BC);
	}
		
}


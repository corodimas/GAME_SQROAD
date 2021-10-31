#pragma once
#include<SFML/Graphics.hpp>
#include<ctime>

class Enemy
{
public: // VARIABLE
	

	sf::Texture car1Texture;
	sf::Sprite car1Sprite;
	std::vector<sf::Sprite> BLuecars;
	

	std::vector<int> Bluecarpos{50,100,150,600,650,850,900 };

	int points;
	float enemySpawnTimer;
	float enemySpawnTimemax;
	int maxEnemies;

private: //FUNCTION
	void inittexture();
	void initsprite();
public:
	Enemy();
	~Enemy();

public:
	void enemyupdate();
	void spawnenemy();
	void enemyrender(sf::RenderTarget& target);

	float x;
	float y;

	float enemyspeed = 10;



};


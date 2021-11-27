#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<ctime>
#include "Player.h"

class Enemy : public Player
{
public: // VARIABLE
	
	sf::Vector2f carspeed;

	sf::Texture car1Texture;
	sf::Sprite car1Sprite;
	
	sf::RectangleShape hitbox;


	std::vector<sf::Sprite> BLuecars;
	

	std::vector<int> Bluecarpos{50,100,150,250,300,450,500,550,600,650,};
	std::vector<int> Bluecarpos2{50,100,150,200,250,300,850,900};
	std::vector<int> Bluecarpos3{ 50,100,150,200,250,300450,500,550,600,700,750,850,900 };
	std::vector<int> Bluecarpos4{ 50,100,150,250,300,450,500,550,600,650,700,750,800,850,900 };
	//1342
	sf::SoundBuffer carrun;
	sf::Sound carrunsound;

	std::vector<sf::Sound> carrunsounds;

	bool playerdeath = false ;
	bool played = false;

	int points;
	float enemySpawnTimer;
	float enemySpawnTimemax;
	float SpawnTime;

	int maxEnemies;
	bool carstop=false;

	float currenttime;
	float itemtime = 500.0f;

	int previousmap;

private: //FUNCTION
	void inittexture();
	void initsprite();
public:
	Enemy();
	~Enemy();

public:
	void enemyupdate(sf::FloatRect playerbound, float& x, float& y,bool &moving, int& map1, int& map2, int& map3, bool& gameover, bool& playstatus, int& score, bool& itempicked, sf::Sprite map[]);
	void spawnenemy(int map);
	void enemyrender(sf::RenderTarget& target);

	float x;
	float y;

	float enemyspeed = 10;



};


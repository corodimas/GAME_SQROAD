#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<ctime>
#include "Player.h"

class Item : public Player
{
public: // VARIABLE


	sf::Texture oaknuttexture;
	sf::Sprite oaknutsprite;


	sf::Texture slowtiemtexture;
	sf::Sprite slowtimesprite;

	std::vector<sf::Sprite>  oaknuts;
	std::vector<int> Oaknutpos{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };

	std::vector<sf::Sprite> slowtimes;
	std::vector<int> slowtimeposx{1, 2, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
	std::vector<int> slowtimeposy{ 1, 2, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 19, 20 };

	sf::SoundBuffer oaksoundbuffer;
	sf::Sound oaksound;

	float ItempawnTimer;
	float ItemspawnTimemax;
	int maxOak = 20;
	int previousmap=0;

	bool itempicked;


	bool spawned = false;

	int i;
private: //FUNCTION
	void inittexture();
	void initsprite();
public:
	Item();
	~Item();

public:
	void Itemupdate(sf::FloatRect playerbound, float& x, float& y, bool& moving, int& map, bool& gameover, bool& playstatus,int& score, float& carspeed);
	void spawItem();
	void Itemrender(sf::RenderTarget& target);
	void spawnslowtimeItem();

	float x;
	float y;



};


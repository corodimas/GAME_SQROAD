#pragma once
#include<SFML/Graphics.hpp>

class Background
{
public:
	sf::Texture watereffect;

	sf::Texture map;

	sf::Texture map2;

	sf::Texture map3;

	sf::Texture map4;


	sf::Sprite mapsprite[8];
	void inittexture();
	void initsprite();

	int i = 0;
	int j = 1;
	int l = j+4;

	int bgt = 0;
	bool changeBG = false;

	int bgy1=-1000;
	int bgy2=0;

public:
	void renderworld(sf::RenderTarget& target);
	void seemlessbackground(float &camerapos, float &playposy, bool& walking);
	void riverflow();


	Background();
	~Background();

};


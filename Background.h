#pragma once
#include<SFML/Graphics.hpp>

class Background
{
private:
	sf::Texture watereffect;

	sf::Texture map;
	sf::Sprite mapsprite;
	void inittexture();
	

public:
	void renderworld(sf::RenderTarget& target);

	void riverflow();


	Background();
	~Background();

};


#pragma once
#include<SFML/Graphics.hpp>
#include"Global.h"

class View 
{
public:

	View();
	~View();

	sf::Texture fame;
	sf::Sprite famesprite;

	void initview();

	void inittexture();
	void initsprite();


	void Update(int playerx, int playery, bool& playerstus);
	void Draw(sf::RenderWindow& window);

	void renderfame(sf::RenderTarget& target);

	sf::Vector2f camerapostion;

protected:
	sf::View camera;

};


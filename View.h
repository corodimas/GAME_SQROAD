#pragma once
#include<SFML/Graphics.hpp>
#include"Global.h"

class View
{
public:

	View();
	~View();

	void initview();
	void Update(int playerx, int playery);
	void Draw(sf::RenderWindow& window);

	sf::Vector2f camerapostion;

protected:
	sf::View camera;

};


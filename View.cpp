#include "View.h"
#include "Player.h"

Player player;


View::View()
{
	this ->initview();
	this->inittexture();
	this->initsprite();
	
}

View::~View()
{
}



void View::initview()
{
	camera.reset(sf::FloatRect(0, 0, 800, 1000));
	camera.setViewport(sf::FloatRect(0.0f, 0.0f, 1.0f, 1.0f));
}

void View::inittexture()
{
	fame.loadFromFile("image/scorefame.png");
	
}

void View::initsprite()
{
	famesprite.setTexture(fame);
	famesprite.setPosition(0, 0);
	famesprite.setScale(sf::Vector2f(0.15f, 0.15f));
}

void View::Update(int playerx,int playery,bool &playerstus)
{
	camerapostion.x = (playerx+25)-200 ;
	if (camerapostion.x < 0)
		camerapostion.x = 0;
	if (camerapostion.x > 400)
		camerapostion.x = 400;

	camerapostion.y = (playery+100)-500;
	if (camerapostion.y > 500)
		camerapostion.y = 500;

	camera.reset(sf::FloatRect(camerapostion.x, camerapostion.y, 400.0f, 500.0f));
	famesprite.setPosition(camerapostion.x,camerapostion.y);
	if (playerstus == true)
	{
		camera.reset(sf::FloatRect(0, 0, 800.0f, 1000.0f));
	}
	else
	{
		camera.reset(sf::FloatRect(camerapostion.x, camerapostion.y, 400.0f, 500.0f));
	}

	
}

void View::Draw(sf::RenderWindow& window)
{
	window.setView(camera);
}

void View::renderfame(sf::RenderTarget& target)
{
	target.draw(famesprite);
}

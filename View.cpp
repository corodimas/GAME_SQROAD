#include "View.h"
#include "Player.h"

Player player;


View::View()
{
	this ->initview();
}

View::~View()
{
}



void View::initview()
{
	camera.reset(sf::FloatRect(0, 0, 800, 1000));
	camera.setViewport(sf::FloatRect(0.0f, 0.0f, 1.0f, 1.0f));
	camera.zoom(5);
}

void View::Update(int playerx,int playery)
{
	camerapostion.x = (playerx+25)-200 ;
	if (camerapostion.x < 0)
		camerapostion.x = 0;
	if (camerapostion.x > 400)
		camerapostion.x = 400;

	camerapostion.y = (playery+50)-500;
	if (camerapostion.y < 0)
		camerapostion.y = 0;
	if (camerapostion.y > 500)
		camerapostion.y = 500;

	camera.reset(sf::FloatRect(camerapostion.x, camerapostion.y, 400.0f, 500.0f));

	
}

void View::Draw(sf::RenderWindow& window)
{
	window.setView(camera);
}

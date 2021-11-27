#include "Item.h"

void Item::inittexture()
{
	oaknuttexture.loadFromFile("image/OAKNUT.png");
	slowtiemtexture.loadFromFile("image/Clock.png");
}

void Item::initsprite()
{
	oaknutsprite.setTexture(oaknuttexture);
	oaknutsprite.setScale(sf::Vector2f(0.025f, 0.025f));

	slowtimesprite.setTexture(slowtiemtexture);
	slowtimesprite.setScale(sf::Vector2f(0.1f, 0.1f));
}	

Item::Item()
{
	inittexture();
	initsprite();
	oaksoundbuffer.loadFromFile("coinpick.wav");
	oaksound.setBuffer(oaksoundbuffer);
	oaksound.setVolume(50);
	ItemspawnTimemax = 0;
	spawItem();
	spawnslowtimeItem();
}

Item::~Item()
{
}

void Item::Itemupdate(sf::FloatRect playerbound, float& x, float& y, bool& moving, int& map, bool& gameover, bool& playstatus,int & score,float &carspeed)
{
	if (map != previousmap)
	{
		oaknuts.clear();
		if(slowtimes.empty()==true)spawnslowtimeItem();
		spawItem();
		
	}

	for (int i=0;i<oaknuts.size();i++)
	{
		if (oaknuts[i].getGlobalBounds().intersects(playerbound))
		{
			oaknuts.erase(this->oaknuts.begin()+i);
			oaksound.play();
			score += 50;
		}
	}
	
	for (int i = 0; i < slowtimes.size(); i++)
	{
		if (slowtimes[i].getGlobalBounds().intersects(playerbound))
		{
			slowtimes.erase(this->slowtimes.begin()+i);
			ItempawnTimer = 0.0f;
			oaksound.play();
			carspeed /= 2;
			itempicked = true;
		}
		
	}
	previousmap = map;
}
	

void Item::spawItem()
{
	for (int i = 0; i < 20; i++)
	{
		int index = rand() % Oaknutpos.size();
		oaknutsprite.setPosition(Oaknutpos[index] * 50, (i * 60));
		oaknuts.push_back(oaknutsprite);
	}
}

void Item::Itemrender(sf::RenderTarget& target)
{
	for (auto& OT: oaknuts)
	{
		target.draw(OT);
	}
	for (auto& ST : slowtimes)
	{
		target.draw(ST);
	}
}

void Item::spawnslowtimeItem()
{
	int indexY = rand() % slowtimeposy.size();
	slowtimesprite.setPosition(450, slowtimeposx[indexY] * 50);
	slowtimes.push_back(this->slowtimesprite);
}

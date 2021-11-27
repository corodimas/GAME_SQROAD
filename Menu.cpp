#include "Menu.h"

Menu::Menu()
{
	x = 325;
	y = 300;

	this->initmenu();
	this->intiselector();
	this->initsprite();
}

Menu::~Menu()
{

}


void Menu::Moveup()
{
	if (selecteditem - 1 >= 0)
	{
		selecteditem--;
		y -= 150;
		selector.setPosition(sf::Vector2f(x, y));
	}
}

void Menu::Movedown()
{
	if (selecteditem + 1 < MAX_ITEM)
	{
		selecteditem++;
		y += 150;
		selector.setPosition(sf::Vector2f(x, y));
	}
}

void Menu::initmenu()
{
	if (!titletexture.loadFromFile("image/test.png"))
	{
		std::cout << "Can't load titlescreen.png \n";
	}

	if(!leaderboardtexture.loadFromFile("image/LEADBOARAD.png"))
	{
		std::cout << "Can't load leaderboard.png \n";
	}
	if (!gameovertexture.loadFromFile("image/Gameover.png"))
	{
		std::cout << "Can'T load gameover.png \n";
	}
}

void Menu::intiselector()
{
	selector.setSize(sf::Vector2f(200.0f, 5.0f));
	selector.setFillColor(sf::Color::Black);
	selector.setPosition(sf::Vector2f(x, y));
}

void Menu::initsprite()
{
	titlesprite.setTexture(titletexture);
	titlesprite.setPosition(0, 0);
	leaderboardsprite.setTexture(leaderboardtexture);
	leaderboardsprite.setPosition(0, 0);
	gameoversprite.setTexture(gameovertexture);
	gameoversprite.setPosition(0, 0);

}

void Menu::rendermenu(sf::RenderTarget& target)
{
	target.draw(titlesprite);
	target.draw(selector);
}

void Menu::menuupdate()
{
	
}

void Menu::renderleaderboard(sf::RenderTarget& target)
{
	target.draw(leaderboardsprite);
}

void Menu::rendergameoverscene(sf::RenderTarget& target)
{
	target.draw(gameoversprite);
}

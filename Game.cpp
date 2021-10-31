#include "Game.h"
#include "Player.h"
#include "Background.h"
#include "ENEMy.h"	



void Game::intitwindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 1000), "SQROAD", sf::Style::Default);
	this->window->setVerticalSyncEnabled(true);

	
}

void Game::initplayer()
{
	this->player = new Player();
}

void Game::initworld()
{
	this->world = new Background();
}

void Game::initenemy()
{
	this->enemy = new Enemy();
}

void Game::initview()
{
	this->view = new View();
}


Game::Game()
{

	this->intitwindow();
	this->initplayer();
	this->initworld();
	this->initenemy();
	this->initview();
}

Game::~Game()
{
	delete this->window;
	delete this->player;
}

void Game::running()
{
	while (this->window->isOpen())
	{

		this->update();
		this->render();
	}
}

void Game::render()
{
	this->window->clear(sf::Color::Blue);
	this->world->renderworld(*this->window);
	this->player->render(*this->window);
	this->enemy->enemyrender(*this->window);
	this->view->Draw(*this->window);
	this->window->display();
}

void Game::update()
{
	while (this->window->pollEvent(ev))
	{
		if (ev.Event::type == sf::Event::Closed)
			this->window->close();
		if (ev.Event::key.code == sf::Keyboard::Escape)
			this->window->close();
	}
	this->view->Update(player->getx(),player->gety());
	this->player->update();
	this->enemy->enemyupdate();
}

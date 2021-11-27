#include "Game.h"
#include "Player.h"
#include "Background.h"
#include "ENEMy.h"	
#include "Score.h"


void Game::intitwindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 1000), "SQROAD", sf::Style::Default);
	this->window->setFramerateLimit(60);

	
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

void Game::initscore()
{
	this->score = new Score();
}

void Game::initmenu()
{
	this->menu = new Menu();
}

void Game::initItem()
{
	this->item = new Item();
}

void Game::updatePollEvent()
{
	sf::Event e;
	LeaderBoard leaderboard("score.txt");
	leaderboard.loadFile();
	while (this->window->pollEvent(e))
	{
		if (e.Event::type == sf::Event::Closed)
			this->window->close();
		if (gameover == true)
		{
			switch (e.type)
			{
			case sf::Event::TextEntered:
				std::cout << e.text.unicode << std::endl;
				if (e.text.unicode == 8)
				{
					if (name.size() > 0) name.erase(name.end() - 1);
				}
				if (e.text.unicode == 13)
				{
					leaderboard.addEntry(name, player->maxdistance);
					player->maxdistance = 0;
					menustate = true;
					gamestate = false;
					gameover = false;
					name = "";
					playerstatus = false;
				}
				if ((e.text.unicode >= 'A' && e.text.unicode <= 'Z') || (e.text.unicode >= 'a' && e.text.unicode <= 'z'))
				{
					if (name.size() < 10) name.push_back(e.text.unicode);

				}
				std::cout << name << std::endl;
				break;
			default:
				break;
			}
		}
		if (menustate == true && gameover == false)
		{
			switch (e.type)
			{
			case sf::Event::KeyReleased:
					switch (e.key.code)
					{
					case sf::Keyboard::Up:
						menu->Moveup();
						break;
					case sf::Keyboard::Down:
						menu->Movedown();
						break;
					case sf::Keyboard::Space:
						switch (menu->GetPressedItem())
						{
						case 0:
							gamestate = true;
							menustate = false;
							break;
						case 1:
							gamestate = false;
							menustate = false;
							leaderboardstate = true;
							break;
						case 2:
							this->window->close();
							break;
						default:
							break;
						}
					default:
						break;
					}
			default:
				break;
			}
		}
		if (leaderboardstate == true)
		{
			switch (e.type)
			{
			case sf::Event::KeyReleased:
				switch (e.key.code)
				{
				case sf::Keyboard::Escape:
					leaderboardstate = false;
					menustate = true;
					break;
				default:
					break;
				}
			default:
				break;
			}
		}
	}
	leaderboard.saveFile();
}



Game::Game()
{

	this->intitwindow();
	this->initplayer();
	this->initworld();
	this->initenemy();
	this->initview();
	this->initscore();
	this->initmenu();
	this->initItem();
}

Game::~Game()
{
	delete this->window;
	delete this->player;
}

void Game::GUIrender()
{
	this->menu->rendermenu(*this->window);
	
}

void Game::running()
{

	
	while (this->window->isOpen())
	{
		
		this->updatePollEvent();
		
		if (gamestate == true)
		{
			this->update();
			this->render();
			if (playerstatus)
			{
				std::stringstream ss;
				sf::Font font;
				font.loadFromFile("MeowsRegular.otf");
				gameover = true;
				this->menu->rendergameoverscene(*this->window);
				text.setFont(font);
				text.setFillColor(sf::Color::White);
				text.setPosition(350.f, 475.f);
				text.setString(name + "_");
				this->window->draw(this->text);
			}
		}
		if (menustate == true)
		{
			this->GUIrender();
		}
		if (leaderboardstate == true)
		{
			LeaderBoard leaderboard("score.txt");
			leaderboard.loadFile();

			this->menu->renderleaderboard(*this->window);
			sf::Text text;
			text.setFont(font);
			font.loadFromFile("MeowsRegular.otf");
			text.setFillColor(sf::Color::Black);
			text.setCharacterSize(60);
			int show_max_entry = 5;
			for (int i = 0; leaderboard.get().size(); i++)
			{
				if (i >= show_max_entry)break;
				text.setPosition(200.f, 200 + (i * 100));
				text.setString(leaderboard.get().at(i).getName());
				window->draw(text);
			}
			for (int i = 0; leaderboard.get().size(); i++)
			{
				if (i >= show_max_entry)break;
				text.setPosition(500, 200 + (i * 100));
				text.setString(std::to_string(leaderboard.get().at(i).getScore()));
				window->draw(text);
			}

		
		}
		this->window->display();
		this->window->clear(sf::Color::Blue);
	}
}

void Game::render()
{
	
	this->world->renderworld(*this->window);
	this->view->Draw(*this->window);
	this->player->render(*this->window);
	this->item->Itemrender(*this->window);
	this->enemy->enemyrender(*this->window);
	this->view->renderfame(*this->window);
	this->score->scorerender(*this->window);
	
}

void Game::update()
{
	
	this->view->Update(player->getx(), player->gety(),playerstatus);
	this->enemy->enemyupdate(player->hitbox.getGlobalBounds(),player->x,player->y,player->walking,world->i,world->j,world->l,gameover,this->playerstatus, player->maxdistance,item->itempicked,world->mapsprite);
	this->player->update();
	this->world->seemlessbackground(view->camerapostion.y,player->y,player->walking);
	this->score->scoreupdata(player->maxdistance,view->camerapostion.x,view->camerapostion.y);
	this->item->Itemupdate(player->sprite.getGlobalBounds(), player->x, player->y, player->walking, world->i, gameover, this->playerstatus,player->maxdistance,enemy->carspeed.x);
}



#pragma once

#include<SFML/Graphics.hpp>
#include<sstream>
#include<fstream>
class Score
{
public:


	int score;
	sf::Text lblscore;
	sf::Font arial;
	std::ostringstream ssScore;


	Score();
	~Score();
	void scoreupdata(int playpos, float& cameraposx, float& cameraposy);

	void scorerender(sf::RenderTarget& target);

	void scorecalculation(int &playpos);

private:
	void initscore();



	
};


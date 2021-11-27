#include "Score.h"
#include <iostream>

void Score::initscore()
{

	lblscore.setCharacterSize(15);
	lblscore.setPosition({ 10,10 });
	if (!arial.loadFromFile("MeowsRegular.otf")) { "Can't load font airal\n"; }
	lblscore.setFont(arial);
	ssScore << "Score: " << score;
	lblscore.setString(ssScore.str());
	lblscore.setFillColor(sf::Color::Black);


}



void Score::scoreupdata(int playpos, float& cameraposx, float& cameraposy)
{
	scorecalculation(playpos);
	ssScore.str(" ");
	ssScore << "Score: " << score;
	lblscore.setString(ssScore.str());
	lblscore.setPosition(cameraposx+25, cameraposy+12);

}



void Score::scorerender(sf::RenderTarget& target)
{
	target.draw(lblscore);
}

void Score::scorecalculation(int &playpos)
{
	score = playpos;
}


Score::Score()
{
	initscore();
	score = 0;


}

Score::~Score()
{
}

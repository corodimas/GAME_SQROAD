#include"Game.h"
#include"SFML/Graphics.hpp"
#include<iostream>
#include<ctime>
#include<SFML/Audio.hpp>

int main()
{
	sf::Music music;
	//sf::Music BGSOUND;
	music.openFromFile("car.wav");
	//BGSOUND.openFromFile("bouncy.wav");
	music.setVolume(5);
	//BGSOUND.setVolume(5);
	music.play();
	//BGSOUND.play();
	music.setLoop(true);
	//BGSOUND.setLoop(true);
	Game game;

	game.running();
}
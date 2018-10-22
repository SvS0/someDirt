#include "TextureHolder.h"
#include "Constants.h"
#include "GaemEntities.h"
#include "EntityData.h"

#include <SFML/Graphics.hpp>

#include <iostream>
#include <map>

using namespace std;

const float FPS = 0.016f;

const int STAGE_STRUCTURE_SIZE = 25 * 25;
int stageTileStructure[STAGE_STRUCTURE_SIZE] = { 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
5, 5, 5, 5, 2, 3, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 2, 3, 4, 5, 5, 5, 5,
5, 5, 5, 5, 59, 60, 61, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 59, 60, 61, 5, 5, 5, 5,
5, 5, 5, 5, 116, 117, 118, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 116, 117, 118, 5, 5, 5, 5,
5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
5, 5, 5, 5, 2, 3, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 2, 3, 4, 5, 5, 5, 5,
5, 5, 5, 5, 59, 60, 61, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 59, 60, 61, 5, 5, 5, 5,
5, 5, 5, 5, 116, 117, 118, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 116, 117, 118, 5, 5, 5, 5,
5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 };

TextureHolder::TexturesType type[] =
{
	TextureHolder::TexturesType::ROGUELIKE
};



int main()
{

	sf::RenderWindow window(sf::VideoMode(800, 640), "SOmeDirt");
	sf::Clock clock;
	sf::Time dt;

	//load resources
	TextureHolder textureHolder(type, 1);


	//START ACTION
	//GETTING
	while (window.isOpen())
	{
		dt = clock.getElapsedTime();
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


		//update


		//render 
		if (dt.asSeconds() > FPS)
		{
			cout << dt.asMilliseconds() << endl;
			window.clear(sf::Color::Blue);
			clock.restart();
			window.display();
		}
		else
		{
			cout << dt.asSeconds() << endl;
		}
		
	}

	return 0;
}
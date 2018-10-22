#include "Constants.h"

#include <SFML/Graphics.hpp>

using namespace std;

#pragma once

class TextureHolder
{

public:

	typedef enum TexturesType
	{
		ROGUELIKE = 0,
		SIZE
	};

public:
	TextureHolder(TexturesType path [], int size);
	~TextureHolder();

public:
	void loadTextures(TexturesType type [], int size);
	sf::Texture getTexture(TexturesType type);

private:
	TexturesType types [MAX_HOLDER_PATH];
	map<string, sf::Texture> texturesMap;
};


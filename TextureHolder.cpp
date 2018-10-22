#include "TextureHolder.h"


TextureHolder::TextureHolder(TexturesType type [], int size)
{
	loadTextures(type, size);
}


TextureHolder::~TextureHolder()
{
}

void TextureHolder::loadTextures(TexturesType type [], int size)
{
	sf::Texture texture;
	map<string, sf::Texture>::iterator it;
	
	for (int i = 0; i < size; i++)
	{
		it = texturesMap.find(texturePath[type[i]]);
		if (it == texturesMap.end())
		{
			texture.loadFromFile(texturePath[type[i]]);
			texturesMap[texturePath[type[i]]] = texture;
		}
	}
}

sf::Texture TextureHolder::getTexture(TexturesType type)
{
	sf::Texture texture;
	map<string, sf::Texture>::iterator it;
	it = texturesMap.find(texturePath[type]);

	if (it == texturesMap.end())
	{
		texture.loadFromFile(texturePath[type]);
		texturesMap[texturePath[type]] = texture;
	}

	return texturesMap[texturePath[type]];
}
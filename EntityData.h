#include <SFML\Graphics.hpp>
#include "Constants.h"

#pragma once

class EntityData
{

public:

	typedef enum EntityType
	{
		NONE = 0,
		ALLY,
		ENEMY,
		SWEET,
		FIELD,
		LWATER,
		RWATER,
		TWATER,
		BWATER,
		LTWATER,
		LBWATER,
		RTWATER,
		RBWATER,
		CWATER,
		SIZE
	};

public:
	EntityData();
	EntityData(EntityType type);
	EntityData(EntityType type, sf::Vector2f pos, sf::Vector2f size);
	~EntityData();

private:
	
	void buildEntity(EntityType type);

public:

	EntityType entityType;
	
	bool drawable;
	unsigned int drawablePond;

	sf::RectangleShape shape;
	sf::VertexArray vertices;

	unsigned int animationsState;
	sf::Time animationsTime[MAX_ANIMATION];

	unsigned int texturePath;
	sf::IntRect textureLocation[MAX_ANIMATION];

};


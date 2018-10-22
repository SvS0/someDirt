#include <SFML\Graphics.hpp>
#include "Constants.h"
#include "EntityData.h"

#pragma once


class GaemEntities
{

public:
	GaemEntities();
	~GaemEntities();

	void update();
	void draw();

public:
	void addEntities(EntityData* data, int size);
	void addEntity(EntityData data);
	void removeEntity(int position);

private:

	void initGameEntities();

	void updatePositions();
	void updateRotations();
	void updateAnimations();
	void updateDrawable();

private:
	void updateInsertPointer();

private:
	int entityCounter;
	int entityInsertPointer;
	EntityData::EntityType entityType[MAX_ENTITY];

	bool drawable[MAX_ENTITY];
	unsigned int drawablePond[MAX_ENTITY];

	sf::RectangleShape shapes[MAX_ENTITY];
	sf::VertexArray vertices[MAX_ENTITY];

	unsigned int animationState[MAX_ENTITY];
	sf::Time animationsTime[MAX_ENTITY][MAX_ANIMATION];

	unsigned int texturePath[MAX_ENTITY];
	sf::IntRect textureLocation[MAX_ENTITY][MAX_ANIMATION];

};

#include "GaemEntities.h"

using namespace std;

GaemEntities::GaemEntities()
{
	entityCounter = 0;
	initGameEntities();
}

GaemEntities::~GaemEntities()
{

}

void GaemEntities::initGameEntities()
{
	entityCounter = 0;
	entityInsertPointer = 0;

	for (int i = 0; i < MAX_ENTITY; ++i)
		entityType[i] = EntityData::EntityType::NONE;
}

void GaemEntities::addEntities(EntityData data)
{

}

void GaemEntities::addEntity(EntityData data)
{
	if (entityCounter < MAX_ENTITY)
	{
		entityType[entityInsertPointer] = data.entityType;

		drawable[entityInsertPointer] = data.drawable;
		drawablePond[entityInsertPointer] = data.drawablePond;

		shapes[entityInsertPointer] = data.shape;

		texturePath[entityInsertPointer] = data.texturePath;

		for (int i = 0; i < MAX_ANIMATION; ++i)
		{
			animationsTime[entityInsertPointer][i] = data.animationsTime[i];
			textureLocation[entityInsertPointer][i] = data.textureLocation[i];
		}

		updateInsertPointer();
	}
}

void GaemEntities::removeEntity(int position)
{
	if (position < MAX_ENTITY)
	{
		entityType[position] = EntityData::EntityType::NONE;
		entityInsertPointer = position;
	}
}

void GaemEntities::updateInsertPointer()
{
	int i = 0;
	while (i < MAX_ENTITY && entityType[i] != EntityData::EntityType::NONE)
		i++;

	entityInsertPointer = i;
}
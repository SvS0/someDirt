#include "EntityData.h"


EntityData::EntityData(EntityType type)
{
	buildEntity(type);
}

EntityData::EntityData(EntityType type, sf::Vector2f pos, sf::Vector2f size)
{
	buildEntity(type);
	shape.setPosition(pos);
	shape.setSize(size);
}

EntityData::~EntityData()
{
}

void EntityData::buildEntity(EntityType type)
{
	if (type != EntityType::NONE)
	{
		
		switch (type)
		{
		case EntityType::ALLY:
			break;
		case EntityType::ENEMY:
			break;
		case EntityType::SWEET:
			break;
		case EntityType::FIELD:
			drawable = true;
			drawablePond = 0;
			animationsState = 0;
			animationsTime[0] = sf::Time::Zero;
			texturePath = 0;
			textureLocation[0] = sf::IntRect(5 * 16 + 5 * 1, 0 * 16 + 0 * 1, 16, 16);
			break;
		case LWATER:
			drawable = true;
			drawablePond = 0;
			animationsState = 0;
			animationsTime[0] = sf::Time::Zero;
			texturePath = 0;
			textureLocation[0] = sf::IntRect(2 * 16 + 2 * 1, 1 * 16 + 1 * 1, 16, 16);
			break;
		case RWATER:
			drawable = true;
			drawablePond = 0;
			animationsState = 0;
			animationsTime[0] = sf::Time::Zero;
			texturePath = 0;
			textureLocation[0] = sf::IntRect(4 * 16 + 4 * 1, 0 * 16 + 0 * 1, 16, 16);
			break;
		case TWATER:
			drawable = true;
			drawablePond = 0;
			animationsState = 0;
			animationsTime[0] = sf::Time::Zero;
			texturePath = 0;
			textureLocation[0] = sf::IntRect(3 * 16 + 3 * 1, 0 * 16 + 0 * 1, 16, 16);
			break;
		case BWATER:
			drawable = true;
			drawablePond = 0;
			animationsState = 0;
			animationsTime[0] = sf::Time::Zero;
			texturePath = 0;
			textureLocation[0] = sf::IntRect(3 * 16 + 3 * 1, 2 * 16 + 2 * 1, 16, 16);
			break;
		case LTWATER:
			drawable = true;
			drawablePond = 0;
			animationsState = 0;
			animationsTime[0] = sf::Time::Zero;
			texturePath = 0;
			textureLocation[0] = sf::IntRect(2 * 16 + 2 * 1, 0 * 16 + 0 * 1, 16, 16);
			break;
		case LBWATER:
			drawable = true;
			drawablePond = 0;
			animationsState = 0;
			animationsTime[0] = sf::Time::Zero;
			texturePath = 0;
			textureLocation[0] = sf::IntRect(2 * 16 + 2 * 1, 2 * 16 + 2 * 1, 16, 16);
			break;
		case RTWATER:
			drawable = true;
			drawablePond = 0;
			animationsState = 0;
			animationsTime[0] = sf::Time::Zero;
			texturePath = 0;
			textureLocation[0] = sf::IntRect(4 * 16 + 4 * 1, 0 * 16 + 0 * 1, 16, 16);
			break;
		case RBWATER:
			drawable = true;
			drawablePond = 0;
			animationsState = 0;
			animationsTime[0] = sf::Time::Zero;
			texturePath = 0;
			textureLocation[0] = sf::IntRect(4 * 16 + 4 * 1, 2 * 16 + 2 * 1, 16, 16);
			break;
		case CWATER:
			drawable = true;
			drawablePond = 0;
			animationsState = 0;
			animationsTime[0] = sf::Time::Zero;
			texturePath = 0;
			textureLocation[0] = sf::IntRect(3 * 16 + 3 * 1, 1 * 16 + 1 * 1, 16, 16);
			break;

		default:
			type = EntityType::NONE;
		}
	}

	entityType = type;
}




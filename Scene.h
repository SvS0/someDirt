#include <SFML\Graphics.hpp>
#include "TextureHolder.h"
#include "GaemEntities.h"
#include <vector>

using namespace std;
#pragma once

class Scene
{

public:
	Scene(TextureHolder& textureHolder, GaemEntities& GaemEntities);
	~Scene();

public:
	void load();
	void update();
	void draw();

private:
	TextureHolder* textures;
	GaemEntities* entities;

};


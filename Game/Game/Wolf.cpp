#include "Wolf.h"


namespace Engine
{
	Wolf::Wolf(GameDataRef data) : Animal(data)
	{

	}

	void Wolf::Spawn(int x, int y)
	{
		sf::Sprite sprite(_data->assets.GetTexture("Wolf Texture"));
		sprite.setPosition(x, y);
		animalSprites.push_back(sprite);
	}

	void Wolf::SpawnRandom()
	{

	}



	Wolf::~Wolf()
	{
	}
}


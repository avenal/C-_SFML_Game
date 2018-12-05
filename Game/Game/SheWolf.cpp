#include "SheWolf.h"


namespace Engine
{
	SheWolf::SheWolf(GameDataRef data) : Animal(data)
	{

	}

	void SheWolf::Spawn(int x, int y)
	{
		sf::Sprite sprite(_data->assets.GetTexture("She Wolf Texture"));
		sprite.setPosition(x, y);
		animalSprites.push_back(sprite);
	}

	void SheWolf::SpawnRandom()
	{

	}

	SheWolf::~SheWolf()
	{
	}
}

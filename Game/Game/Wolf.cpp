#include "Wolf.h"


namespace Engine
{
	Wolf::Wolf(GameDataRef data) : Animal(data)
	{

	}
	void Wolf::DrawWolves()
	{
		for (unsigned int i = 0; i < animalSprites.size(); i++)
		{
			_data->window.draw(animalSprites.at(i));
		}
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

	void Wolf::Move(float dt)
	{
		std::srand(std::time(NULL));
		for (unsigned int i = 0; i < animalSprites.size(); i++)
		{
			int random = rand() % 8;
			sf::Vector2f position = animalSprites.at(i).getPosition();
			float movement = ANIMAL_MOVEMENT_SPEED * dt;
			if (random == 0)//up
			{
				animalSprites.at(i).move(0, -movement);
			}//down
			else if (random == 1)
			{
				animalSprites.at(i).move(0, movement);
			}//left
			else if (random == 2)
			{
				animalSprites.at(i).move(-movement, 0);
			}
			else if (random == 3)
			{
				animalSprites.at(i).move(movement, 0);
			}
		}
		 
	}

	Wolf::~Wolf()
	{
	}
}


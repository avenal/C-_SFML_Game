#include "Animal.h"

namespace Engine
{
	Animal::Animal(GameDataRef data) : _data(data)
	{

	}
	void Animal::DrawAnimals()
	{
		for (unsigned int i = 0; i < animalSprites.size(); i++)
		{
			_data->window.draw(animalSprites.at(i));
		}
	}
	

	Animal::~Animal()
	{
		delete [] &animalSprites;
	}
}
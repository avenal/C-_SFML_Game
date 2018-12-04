#pragma once
#include <SFML\Graphics.hpp>
#include "Game.h"
#include <vector>


namespace Engine 
{
	class Animal
	{
	public:
		
		Animal(GameDataRef data);
		void DrawAnimals();
		
		~Animal();
	protected:
		GameDataRef _data;
		std::vector<sf::Sprite> animalSprites;
		
	};
}




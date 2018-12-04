#pragma once
#include "Animal.h"
#include <stdlib.h>    
#include <time.h>  
#include "DEFINITIONS.h"
namespace Engine
{
	class Wolf: public Animal
	{
	public:
		Wolf(GameDataRef data);
		void DrawWolves();
		void Spawn(int x, int y);
		void SpawnRandom();
		void Move(float dt);
		~Wolf();
	private:

		
	};

}



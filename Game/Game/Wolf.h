#pragma once
#include "Animal.h"
#include <stdlib.h>    
#include <time.h>  


namespace Engine
{
	class Wolf: public Animal
	{
	public:
		Wolf(GameDataRef data);
		void Spawn(int x, int y);
		void SpawnRandom();
		~Wolf();
	private:

		
	};

}



#pragma once
#include "Animal.h"
#include <stdlib.h>    
#include <time.h>  

namespace Engine
{
	class SheWolf : public Animal
	{
	public:
		SheWolf(GameDataRef data);
		void Spawn(int x, int y);
		void SpawnRandom();
		~SheWolf();
	private:


	};

}

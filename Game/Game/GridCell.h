#pragma once
#include <vector>
#include"Game.h"
#include<SFML\Graphics.hpp>

namespace Engine
{
	class GridCell
	{
	public:
		GridCell(int posX, int posY, GameDataRef data);
		void ClearCell();
		void AddWolf(int index);
		void AddSheWolf(int index);
		void AddHare(int index);
		std::vector<int> GetWolfSprites();
		std::vector<int> GetSheWolfSprites();
		std::vector<int> GetHareSprites();
		sf::Sprite GetCellSprite();
		~GridCell();
	private:
		GameDataRef _data;
		std::vector<int> wolfSprites;
		std::vector<int> sheWolfSprites;
		std::vector<int> hareSprites;
		sf::Sprite gridCellSprite;
	};

}

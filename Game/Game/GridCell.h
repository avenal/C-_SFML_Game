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
		void AddWolf(sf::Sprite *wolf);
		void AddSheWolf(sf::Sprite *sheWolf);
		void AddHare(sf::Sprite *hare);
		std::vector<sf::Sprite*> GetWolfSprites();
		std::vector<sf::Sprite*> GetSheWolfSprites();
		std::vector<sf::Sprite*> GetHareSprites();
		sf::Sprite GetCellSprite();
		~GridCell();
	private:
		GameDataRef _data;
		std::vector<sf::Sprite*> wolfSprites;
		std::vector<sf::Sprite*> sheWolfSprites;
		std::vector<sf::Sprite*> hareSprites;
		sf::Sprite gridCellSprite;
	};

}

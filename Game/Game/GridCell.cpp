#include "GridCell.h"

namespace Engine 
{
	GridCell::GridCell(int posX, int posY, GameDataRef data) :_data(data)
	{
		gridCellSprite.setTexture(_data->assets.GetTexture("Grass Texture"));
		gridCellSprite.setPosition(posX * 32, posY * 32);
	}

	void GridCell::ClearCell()
	{
		wolfSprites.clear();
		sheWolfSprites.clear();
		hareSprites.clear();
	}

	void GridCell::AddWolf(sf::Sprite * wolf)
	{
		wolfSprites.push_back(wolf);
	}

	void GridCell::AddSheWolf(sf::Sprite * sheWolf)
	{
		sheWolfSprites.push_back(sheWolf);
	}

	void GridCell::AddHare(sf::Sprite * hare)
	{
		hareSprites.push_back(hare);
	}

	std::vector<sf::Sprite*> GridCell::GetWolfSprites()
	{
		return wolfSprites;
	}

	std::vector<sf::Sprite*> GridCell::GetSheWolfSprites()
	{
		return sheWolfSprites;
	}

	std::vector<sf::Sprite*> GridCell::GetHareSprites()
	{
		return hareSprites;
	}

	sf::Sprite GridCell::GetCellSprite()
	{
		return gridCellSprite;
	}

	GridCell::~GridCell()
	{
	}
	
}

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

	void GridCell::AddWolf(int index)
	{
		wolfSprites.push_back(index);
	}

	void GridCell::AddSheWolf(int index)
	{
		sheWolfSprites.push_back(index);
	}

	void GridCell::AddHare(int index)
	{
		hareSprites.push_back(index);
	}

	std::vector<int> GridCell::GetWolfSprites()
	{
		return wolfSprites;
	}

	std::vector<int> GridCell::GetSheWolfSprites()
	{
		return sheWolfSprites;
	}

	std::vector<int> GridCell::GetHareSprites()
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

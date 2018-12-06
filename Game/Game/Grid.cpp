#include "Grid.h"

namespace Engine
{
	Grid::Grid(GameDataRef data): _data(data)
	{

	}

	void Grid::InitializeCells(unsigned int x, unsigned int y)
	{
		for (unsigned int i = 0; i < x; i++) {
			for (unsigned int j = 0; j < y; j++) {
				GridCell* c = new GridCell(j, i, _data);
				cells.push_back(c);
			}
		}
	}

	void Grid::DrawCells()
	{
		for (unsigned int i = 0; i < cells.size(); i++)
		{
			_data->window.draw(cells.at(i)->GetCellSprite());
		}
	}

	std::vector<GridCell*> Grid::GetGridCells()
	{
		return cells;
	}

	void Grid::Insert(std::vector<sf::Sprite> wolf, std::vector<sf::Sprite> sheWolf, std::vector<sf::Sprite> hare)
	{
		Collision collision;
		/*for (unsigned int j = 0; j < cells.size(); j++)
		{
			for (unsigned int i = 0; i < wolf.size(); i++)
			{
				if (collision.CheckCollision(cells.at(j)->GetCellSprite(), wolf.at(i)))
				{
					cells.at(j)->AddWolf(&wolf.at(i));
				}
			}
			for (unsigned int i = 0; i < sheWolf.size(); i++)
			{
				if (collision.CheckCollision(cells.at(j)->GetCellSprite(), sheWolf.at(i)))
				{
					cells.at(j)->AddSheWolf(&sheWolf.at(i));
				}
			}
			for (unsigned int i = 0; i < hare.size(); i++)
			{
				if (collision.CheckCollision(cells.at(j)->GetCellSprite(), hare.at(i)))
				{
					cells.at(j)->AddHare(&hare.at(i));
				}
			}
		}*/
		for (int i = 0; i < wolf.size(); i++)
		{
			int indexes[4] = { 0, 0, 0, 0};
			int x = wolf.at(i).getPosition().x/32;
			int y = wolf.at(i).getPosition().y / 32;
			indexes[0] = x * 20 + y;
			cells.at(indexes[0])->AddWolf(i);
			x = (wolf.at(i).getPosition().x +16)/ 32;
			y = wolf.at(i).getPosition().y / 32;
			indexes[1] = x * 20 + y;
			if (indexes[1] != indexes[0]) {
				cells.at(indexes[1])->AddWolf(i);
			}
			x = (wolf.at(i).getPosition().x ) / 32;
			y = (wolf.at(i).getPosition().y + 16)/ 32;
			indexes[2] = x * 20 + y;
			if (indexes[2] != indexes[0] && indexes[2] != indexes[1]) {
				cells.at(indexes[2])->AddWolf(i);
			}
			x = (wolf.at(i).getPosition().x + 16) / 32;
			y = (wolf.at(i).getPosition().y + 16) / 32;
			indexes[3] = x * 20 + y;
			if (indexes[3] != indexes[0] && indexes[3] != indexes[1] && indexes[3] != indexes[2]) {
				cells.at(indexes[3])->AddWolf(i);
			}
		//	delete[] indexes;
		}
		for (int i = 0; i < sheWolf.size(); i++)
		{
			int indexes[4] = { 0, 0, 0, 0 };
			int x = sheWolf.at(i).getPosition().x / 32;
			int y = sheWolf.at(i).getPosition().y / 32;
			indexes[0] = x * 20 + y;
			cells.at(indexes[0])->AddSheWolf(i);
			x = (sheWolf.at(i).getPosition().x + 16) / 32;
			y = sheWolf.at(i).getPosition().y / 32;
			indexes[1] = x * 20 + y;
			if (indexes[1] != indexes[0]) {
				cells.at(indexes[1])->AddSheWolf(i);
			}
			x = (sheWolf.at(i).getPosition().x) / 32;
			y = (sheWolf.at(i).getPosition().y + 16) / 32;
			indexes[2] = x * 20 + y;
			if (indexes[2] != indexes[0] && indexes[2] != indexes[1]) {
				cells.at(indexes[2])->AddSheWolf(i);
			}
			x = (sheWolf.at(i).getPosition().x + 16) / 32;
			y = (sheWolf.at(i).getPosition().y + 16) / 32;
			indexes[3] = x * 20 + y;
			if (indexes[3] != indexes[0] && indexes[3] != indexes[1] && indexes[3] != indexes[2]) {
				cells.at(indexes[3])->AddSheWolf(i);
			}
			//	delete[] indexes;
		}
		for (int i = 0; i < hare.size(); i++)
		{
			int indexes[4] = { 0, 0, 0, 0 };
			int x = hare.at(i).getPosition().x / 32;
			int y = hare.at(i).getPosition().y / 32;
			indexes[0] = x * 20 + y;
			cells.at(indexes[0])->AddHare(i);
			x = (hare.at(i).getPosition().x + 16) / 32;
			y = hare.at(i).getPosition().y / 32;
			indexes[1] = x * 20 + y;
			if (indexes[1] != indexes[0]) {
				cells.at(indexes[1])->AddHare(i);
			}
			x = (hare.at(i).getPosition().x) / 32;
			y = (hare.at(i).getPosition().y + 16) / 32;
			indexes[2] = x * 20 + y;
			if (indexes[2] != indexes[0] && indexes[2] != indexes[1]) {
				cells.at(indexes[2])->AddHare(i);
			}
			x = (hare.at(i).getPosition().x + 16) / 32;
			y = (hare.at(i).getPosition().y + 16) / 32;
			indexes[3] = x * 20 + y;
			if (indexes[3] != indexes[0] && indexes[3] != indexes[1] && indexes[3] != indexes[2]) {
				cells.at(indexes[3])->AddHare(i);
			}
			//	delete[] indexes;
		}
		

	}

	void Grid::ClearGrid()
	{
		for (unsigned int i = 0; i < cells.size(); i++)
		{
			cells.at(i)->ClearCell();
		}
	}

	void Grid::WolfCollideWithHare(std::vector<sf::Sprite> *wolf, std::vector<sf::Sprite> *sheWolf, std::vector<sf::Sprite> *hare)
	{
		Collision collision;
		int k = 0;
		for (int i = 0; i < cells.size(); i++)
		{
		
			for (int j = 0; j < cells.at(i)->GetWolfSprites().size(); j++)
			{
				for (int z = 0; z < cells.at(i)->GetHareSprites().size(); z++)
				{
					//zamien to na wektor z numerami indeksow
					if (hare->size() > z-k) {
						if (collision.CheckCollision(&(*wolf).at(cells.at(i)->GetWolfSprites().at(j)), &(*hare).at(cells.at(i)->GetHareSprites().at(z-k))))
						{
							(*hare).erase(hare->begin() + cells.at(i)->GetHareSprites().at(z - k));
							//cells.at(i)->GetHareSprites().erase(cells.at(i)->GetHareSprites().begin() + z);
							k++;			
						}
					}
					
					/*if (collision.CheckCollision(cells.at(i)->GetWolfSprites().at(j), cells.at(i)->GetHareSprites().at(z)))
					{

						std::cout << "xd";*/
						//(*hare).erase(std::remove((*hare).begin(), (*hare).end(), *cells.at(i)->GetHareSprites().at(z)), (*hare).end());
					/*	for (auto itr = (*hare).begin(); itr != (*hare).end();) {
							if (&*itr == cells.at(i)->GetHareSprites().at(z)) {
								itr = (*hare).erase(itr);
							}
							else {
								++itr;
							}

						}*/
				}
			}
			
		}
	}
		/*for (int j = 0; j < wolf->size(); j++)
		{
			for (int i = 0; i < hare->size(); i++)
			{
				if (collision.CheckCollision(&(*wolf).at(j), &(*hare).at(i)))
				{
					(*hare).erase((*hare).begin() + i);
					i--;
				}
			}
		}*/

	void Grid::HareCollideWithHare(std::vector<sf::Sprite> *wolf, std::vector<sf::Sprite> *sheWolf, std::vector<sf::Sprite> *hare)
	{
		Collision collision;
		for (int i = 0; i < cells.size(); i++)
		if (cells.at(i)->GetHareSprites().size() > 1 && hare->size() < 500)
		{
		for (int a = 0; a < cells.at(i)->GetHareSprites().size() - 1; a++)
		{
		for (int b = a + 1; b < cells.at(i)->GetHareSprites().size(); b++)
		{

		int random = rand() % 1000;
		if (random < 15)
		{
		if (a < hare->size() && b < hare->size() && a < cells.at(i)->GetHareSprites().size() && b < cells.at(i)->GetHareSprites().size()) {

		if (collision.CheckCollision(&(*hare).at(cells.at(i)->GetHareSprites().at(a)), &(*hare).at(cells.at(i)->GetHareSprites().at(b))))
		{
		sf::Sprite sprite(_data->assets.GetTexture("Hare Texture"));
		sprite.setPosition((*hare).at(cells.at(i)->GetHareSprites().at(a)).getPosition().x + 10, (*hare).at(cells.at(i)->GetHareSprites().at(a)).getPosition().y - 10);
		hare->push_back(sprite);
		random = (rand() + i) % 1000;
		break;
		}
		}

		}
		}
		}
		}
		
	}
	Grid::~Grid()
	{
	}

}
	
	



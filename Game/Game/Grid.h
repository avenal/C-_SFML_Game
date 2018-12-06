#pragma once
#include<vector>
#include<SFML\Graphics.hpp>
#include"GridCell.h"
#include"Game.h"
#include "Animal.h"
#include "Wolf.h"
#include "SheWolf.h"
#include "Hare.h"
#include "Collision.h"
#include <vector>
#include<iostream>
namespace Engine
{
	class Grid
	{
	public:
		Grid(GameDataRef data);
		void InitializeCells(unsigned int x, unsigned int y);
		void DrawCells();
		std::vector<GridCell*> GetGridCells();
		void Insert(std::vector<sf::Sprite> wolf, std::vector<sf::Sprite> sheWolf, std::vector<sf::Sprite> hare);
		void ClearGrid();
		void WolfCollideWithHare(std::vector<sf::Sprite> *wolf, std::vector<sf::Sprite> *sheWolf, std::vector<sf::Sprite> *hare);
		void HareCollideWithHare(std::vector<sf::Sprite> *wolf, std::vector<sf::Sprite> *sheWolf, std::vector<sf::Sprite> *hare);
		~Grid();
	private:
		GameDataRef _data;
		std::vector<GridCell*> cells;
	};
}


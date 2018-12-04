#include "GameState.h"
#include <sstream>
#include <iostream>
#include "DEFINITIONS.h"

namespace Engine {
	GameState::GameState(GameDataRef data) :_data(data)
	{

	}
	void GameState::Init()
	{
		this->_data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
		_background.setTexture(this->_data->assets.GetTexture("Game Background"));
		this->_data->assets.LoadTexture("Wolf Texture", WOLF_FILEPATH);
	
		this->_data->assets.LoadTexture("She Wolf Texture", SHE_WOLF_FILEPATH);
		
		this->_data->assets.LoadTexture("Hare Texture", HARE_FILEPATH);
		
		wolf = new Wolf(_data);
	}
	void GameState::HandleInput()
	{
		sf::Event event;
		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}
			if (this->_data->input.IsSpriteClicked(_background, sf::Mouse::Left, _data->window))
			{
				std::cout << "draw";
				wolf->Spawn(sf::Mouse::getPosition(_data->window).x, sf::Mouse::getPosition(_data->window).y);
			}
		}
	}
	void GameState::Update(float dt)
	{
		wolf->Move(dt);
	}
	void GameState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Red);
		this->_data->window.draw(this->_background);
		wolf->DrawWolves();
		
		this->_data->window.display();
	}
}

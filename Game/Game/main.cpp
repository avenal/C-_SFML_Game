#include<SFML\Graphics.hpp>
int main() {
	sf::RenderWindow Window;
	Window.create(sf::VideoMode(800, 640), "Game");
	Window.setFramerateLimit(30);
	while (Window.isOpen())
	{
		sf::Event event;
		while (Window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				Window.close();
			}
		}
	}
}
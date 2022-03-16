#pragma once
#include <SFML/Graphics.hpp>

class Engine
{
	private:
		sf::RenderWindow window;
		sf::Color bgColor;
		sf::Color snakeColor;
		
		void input();
		void update(float interval);
		void draw();
	public:
		Engine();
		void start();
};

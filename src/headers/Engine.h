#pragma once
#include <SFML/Graphics.hpp>
#include "Snake.h"

class Engine
{
	private:
		sf::RenderWindow window;
		sf::Color bgColor;
		sf::Color borderColor;
		sf::Color snakeColor;
		sf::View view;
		sf::RectangleShape border;
		Snake snake;
		
		void input();
		void update(float interval);
		void draw();
	public:
		Engine();
		void start();
};

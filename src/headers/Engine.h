#pragma once
#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "Food.h"
#include "HUD.h"

class Engine
{
	private:
		sf::RenderWindow window;
		sf::Color bgColor;
		sf::Color borderColor;
		sf::Color snakeColor;
		sf::Color foodColor;
		sf::Color hudTextColor;
		sf::View view;
		sf::View hudView;
		sf::RectangleShape border;
		Snake snake;
		Food *food;
		HUD hud;
		
		void input();
		void update(float interval);
		void draw();
	public:
		Engine();
		~Engine();
		void start();
};

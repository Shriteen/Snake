#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Menu
{
    private:
	std::vector<sf::Text> options;
        sf::Font font;
	sf::Color fontColor;
	float fontSize;
	float vertPadding;
	int selected;

    public:
        Menu(std::vector<std::string> options,
	     sf::Color fontColor,
	     float fontSize);
	void draw(sf::RenderWindow &window);
	std::string getSelected();
	void keyHandle(sf::Event &event);
	bool mouseHandle(sf::Event &event,sf::RenderWindow &window);
};

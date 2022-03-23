#pragma once
#include <SFML/Graphics.hpp>

enum class colorScheme {light,dark};

class DarkModeToggle
{
    private:
        sf::Texture toLight;
        sf::Texture toDark;
        sf::Sprite sprite;
    public:
        DarkModeToggle();
        void update(colorScheme scheme);
        void draw(sf::RenderWindow &window);
        bool isClicked(sf::Event &event,sf::RenderWindow &window);
};

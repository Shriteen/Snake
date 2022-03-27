#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>

class Menu
{
    private:
        std::vector<sf::Text> options;
        sf::Font font;
        sf::Color fontColor;
        float fontSize;
        sf::FloatRect bounds;
        int selected;
        sf::SoundBuffer changeOptionSoundBuffer;
        sf::Sound changeOptionSound;

    public:
        Menu(std::vector<std::string> options,
             sf::FloatRect bounds,
             sf::Color fontColor,
             float fontSize);
        void draw(sf::RenderWindow &window);
        std::string getSelected();
        void keyHandle(sf::Event &event);
        bool mouseHandle(sf::Event &event,sf::RenderWindow &window);
};

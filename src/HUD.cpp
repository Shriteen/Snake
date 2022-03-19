#include <string>
#include "headers/HUD.h"

HUD::HUD(sf::Color fontColor)
{
    font.loadFromFile("fonts/Coolville.ttf");
    scoreText.setFont(font);
    
    fontSize=50.0;
    this->fontColor=fontColor;
    scoreText.setCharacterSize(fontSize);
    scoreText.setPosition(25,6);
}

void HUD::update(Snake &snake)
{
    scoreText.setString("SCORE: "+std::to_string(snake.getScore()));
    scoreText.setFillColor(fontColor);
}

void HUD::draw(sf::RenderWindow &window)
{
    window.draw(scoreText);
}

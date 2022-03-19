#include <string>
#include "headers/HUD.h"

HUD::HUD()
{
    font.loadFromFile("fonts/Coolville.ttf");
    scoreText.setFont(font);
    
    fontSize=10.0;
    fontColor=sf::Color::Magenta;
    scoreText.setPosition(50,50);
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

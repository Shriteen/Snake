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
    
    pauseTexture.loadFromFile("images/button_pause.png");
    playTexture.loadFromFile("images/button_play.png");
    
    pauseOrPlayButton.setColor(fontColor);
    pauseOrPlayButton.setPosition(1000,20);
}

void HUD::update(Snake &snake,bool playing)
{
    scoreText.setString("SCORE: "+std::to_string(snake.getScore()));
    scoreText.setFillColor(fontColor);
    
    if(playing)
    {
        pauseOrPlayButton.setTexture(pauseTexture);
    }
    else
    {
        pauseOrPlayButton.setTexture(playTexture);
    }
}

void HUD::draw(sf::RenderWindow &window)
{
    window.draw(scoreText);
    window.draw(pauseOrPlayButton);
}

sf::FloatRect HUD::getPauseOrPlayButtonBounds()
{
    return pauseOrPlayButton.getGlobalBounds();
}

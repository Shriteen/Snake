#include "headers/GameOverDialogue.h"

GameOverDialogue::GameOverDialogue(sf::FloatRect bounds,sf::Color fontColor):
    bounds(bounds),
    fontColor(fontColor),
    menu(std::vector<std::string>{"Play Again","Exit To Menu"},
         bounds,
         fontColor,
         50)
{
    font.loadFromFile("fonts/Coolville.ttf");
    gameOverText.setFont(font);
    scoreText.setFont(font);
    
    gameOverText.setCharacterSize(80);
    scoreText.setCharacterSize(65);
    
    gameOverText.setString("Game Over!");
    
    gameOverText.setPosition( bounds.left+((bounds.width - gameOverText.getGlobalBounds().width )/2.0),  0 );
    
}

void GameOverDialogue::draw(sf::RenderWindow &window)
{
    scoreText.setString("SCORE: "+std::to_string(score));
    scoreText.setPosition(bounds.left+((bounds.width - scoreText.getGlobalBounds().width )/2.0),
                          gameOverText.getGlobalBounds().height * 2 );
    
    scoreText.setFillColor(fontColor);
    gameOverText.setFillColor(fontColor);
    
    window.draw(gameOverText);
    window.draw(scoreText);
    
    menu.draw(window);
}

void GameOverDialogue::setScore(int score)
{
    this->score = score;
}

std::string GameOverDialogue::getSelected()
{
    return menu.getSelected();
}

void GameOverDialogue::keyHandle(sf::Event &event)
{
    menu.keyHandle(event);
}

bool GameOverDialogue::mouseHandle(sf::Event &event,sf::RenderWindow &window)
{
    return menu.mouseHandle(event,window);
}

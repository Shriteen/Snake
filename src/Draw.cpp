#include "headers/Engine.h"

void Engine::draw()
{
    window.setView(view);
    
    window.clear(bgColor);
        
        
    sf::RectangleShape rect(sf::Vector2f(1080,720));
    rect.setOutlineColor(sf::Color::Red);
    rect.setOutlineThickness(-10);
    //rect.setPosition(sf::Vector2f());
    window.draw(rect);
        
    sf::CircleShape circle(50);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(100,100);
    window.draw(circle);
    
    
    
    
    window.display();
}

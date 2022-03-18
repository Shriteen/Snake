#include "headers/Food.h"

std::default_random_engine Food::randEngine =
                    std::default_random_engine( std::chrono::system_clock::now().time_since_epoch().count() );

Food::Food(sf::FloatRect bounds,sf::Color foodColor)
{
    int x=float(bounds.width-(2*Pixel::size))/float(Pixel::size);
    int y=float(bounds.height-(2*Pixel::size))/float(Pixel::size);
    
    std::uniform_int_distribution w_distribution(0,x);
    std::uniform_int_distribution h_distribution(0,y);
    
    position.x = bounds.left+(Pixel::size/1.65) + ((w_distribution(randEngine)+1) * Pixel::size);
    position.y = bounds.top+(Pixel::size/2.3) + ((h_distribution(randEngine)+1) * Pixel::size);
    
    color = foodColor;
    
    update();
}

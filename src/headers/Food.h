#pragma once
#include <SFML/Graphics.hpp>
#include <random>
#include <chrono>
#include "Pixel.h"

class Food:public Pixel
{
    private:
        
    public:
        static std::default_random_engine randEngine;
        
        Food(sf::FloatRect bounds,sf::Color foodColor);
};

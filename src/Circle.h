#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Circle
{
public:
    Circle(sf::Vector2f position);
    void draw(sf::RenderWindow &window) const;
    void update(float deltaTime);

private:
    sf::CircleShape shape;
    float radius;
    sf::Vector2f velocity = {80.0f, 80.0f};
    float r = 250.0f;
    float g = 250.0f;
    float b = 150.0f;
    sf::Color color = sf::Color(r, g, b);
};
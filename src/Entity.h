#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
class Entity
{
public:
    Entity(const sf::Texture &texture);

    // Virtual destructor for safe polymorphic deletion
    virtual ~Entity() = default;

    // Draw: virtual so that derived classes can override
    virtual void draw(sf::RenderWindow &window) const;
    virtual void update(float deltaTime) = 0;

protected:
    sf::Sprite mSprite; // Derived classes can access this if needed
};
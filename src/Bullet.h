#include <iostream>
#include <SFML/Graphics.hpp>
#include "Entity.h"
#pragma once

class Bullet : public Entity

{
public:
    Bullet(const sf::Texture &texture, sf::Vector2f position, float mSpeed);
    void update(float deltaTime) override;
    void draw(sf::RenderWindow &window) const override;

private:
    float mSpeed;
};
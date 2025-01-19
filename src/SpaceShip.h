#pragma once

#include "Entity.h"

class SpaceShip : public Entity
{
public:
    SpaceShip(const sf::Texture &texture, sf::Vector2f position);
    void draw(sf::RenderWindow &window) const override;
    void update(float deltaTime) override;
    void fireBullet();

private:
    float speed = 100.0f;
};
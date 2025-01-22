#include "Bullet.h"

Bullet::Bullet(const sf::Texture &texture, sf::Vector2f position, float mSpeed) : Entity(texture)
{
    mSprite.setPosition(position);
    mSprite.setScale({1.0f, 1.0f});
}

sf::Vector2f Bullet::getPosition() const
{
    return mSprite.getPosition();
}

void Bullet::update(float deltaTime)
{
}

void Bullet::draw(sf::RenderWindow &window) const
{
    Entity::draw(window);
}
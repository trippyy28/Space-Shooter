#include "SpaceShip.h"

SpaceShip::SpaceShip(const sf::Texture &texture, sf::Vector2f position)
    : Entity(texture) // Call the base class constructor
{
    mSprite.setPosition(position); // Set the initial position
    mSprite.setScale({4.0f, 4.0f});
}

void SpaceShip::update(float deltaTime)
{
    // keyboard input
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Left))
    {
        mSprite.move({-3.f, 0.f});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right))
    {
        mSprite.move({3.f, 0.f});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Up))
    {
        mSprite.move({0.f, -3.f});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Down))
    {
        mSprite.move({0.f, 3.f});
    }

    // boundry check
    if (mSprite.getPosition().x < 0)
    {
        mSprite.setPosition({0, mSprite.getPosition().y});
    }
    if (mSprite.getPosition().x > 800)
    {
        mSprite.setPosition({800, mSprite.getPosition().y});
    }
    if (mSprite.getPosition().y < 0)
    {
        mSprite.setPosition({mSprite.getPosition().x, 0});
    }
    if (mSprite.getPosition().y > 540)
    {
        mSprite.setPosition({mSprite.getPosition().x, 540});
    }
}
void SpaceShip::draw(sf::RenderWindow &window) const
{
    Entity::draw(window); // Use the base class draw function
}

bool SpaceShip::shouldFireBullet() const
{
    return sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Space);
}
sf::Vector2f SpaceShip::getPosition() const
{
    return mSprite.getPosition();
}
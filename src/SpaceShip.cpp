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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Space))
    {
        fireBullet();
    }
}
void SpaceShip::draw(sf::RenderWindow &window) const
{
    Entity::draw(window); // Use the base class draw function
}

void SpaceShip::fireBullet()
{
    std::cout << "Firing bullet!" << std::endl;
    // Create a new bullet entity
    // mBullets.emplace_back(mResourceManager.getTexture("Bullet"), mSprite.getPosition(), sf::Vector2f(0.0f, -1.0f), 200.0f);
}

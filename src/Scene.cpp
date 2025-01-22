#include "Scene.h"
#include <iostream>

Scene ::Scene(ResourceManager &resourceManager) : mResourceManager(resourceManager),
                                                  mSpaceShip(resourceManager.getTexture("SpaceShip"), sf::Vector2f(100.0f, 100.0f)), mBullet(resourceManager.getTexture("Bullet"), sf::Vector2f(50.0f, 100.0f), 0.0f)
{
}

void Scene::update(sf::Time deltaTime)
{
    mSpaceShip.update(deltaTime.asSeconds());
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Space))
    { // Example input
        fireBullet(mSpaceShip.getPosition() + sf::Vector2f(0.0f, -10.0f));
    }

    // Update bullets
    for (auto &bullet : mBullets)
    {
        bullet.update(deltaTime.asSeconds());
    }
    for (auto &bullet : mBullets)
    {
        bullet.update(deltaTime.asSeconds());
        mBullets.erase(std::remove_if(mBullets.begin(), mBullets.end(),
                                      [](const Bullet &bullet)
                                      {
                                          return bullet.getPosition().y < 0; // Example condition
                                      }),
                       mBullets.end());
    }
}

void Scene::draw(sf::RenderWindow &window)
{
    mSpaceShip.draw(window);
    for (const auto &bullet : mBullets)
    {
        bullet.draw(window);
    }
}

void Scene::fireBullet(const sf::Vector2f &position)
{
    mBullets.emplace_back(mResourceManager.getTexture("Bullet"), position, 300.0f); // Example speed
}
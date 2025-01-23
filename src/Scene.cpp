#include "Scene.h"
#include <iostream>
constexpr size_t MAX_BULLETS = 1000;
Scene ::Scene(ResourceManager &resourceManager) : mResourceManager(resourceManager),
                                                  mSpaceShip(resourceManager.getTexture("SpaceShip"), sf::Vector2f(100.0f, 100.0f)), mBullet(resourceManager.getTexture("Bullet"), sf::Vector2f(50.0f, 100.0f), 0.0f), mBtn(sf::Vector2f(100.0f, 100.0f), sf::Vector2f(50.0f, 50.0f))
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
    // for (auto &bullet : mBullets)
    // {
    //     bullet.update(deltaTime.asSeconds());
    //     mBullets.erase(std::remove_if(mBullets.begin(), mBullets.end(),
    //                                   [](const Bullet &bullet)
    //                                   {
    //                                       return bullet.getPosition().y < 0; // Example condition
    //                                   }),
    //                    mBullets.end());
    // }
}

void Scene::draw(sf::RenderWindow &window)
{
    mSpaceShip.draw(window);
    mBtn.draw(window);
    for (const auto &bullet : mBullets)
    {
        bullet.draw(window);
    }
}

// void Scene::fireBullet(const sf::Vector2f &position)
// {
//     mBullets.emplace_back(mResourceManager.getTexture("Bullet"), position, 300.0f); // Example speed
//     std::cout << mBullets.size() << std::endl;
// }
void Scene::fireBullet(const sf::Vector2f &position)
{
    if (mBullets.size() >= MAX_BULLETS)
    {
        mBullets.erase(mBullets.begin()); // Remove the oldest bullet
    }

    mBullets.emplace_back(mResourceManager.getTexture("Bullet"), position, 300.0f); // Add the new bullet
    std::cout << "Total bullets: " << mBullets.size() << std::endl;
}
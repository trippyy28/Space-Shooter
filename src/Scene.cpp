#include "Scene.h"
#include <iostream>

Scene ::Scene(ResourceManager &resourceManager) : mResourceManager(resourceManager),
                                                  mSpaceShip(resourceManager.getTexture("SpaceShip"), sf::Vector2f(100.0f, 100.0f)), mBullet(resourceManager.getTexture("Bullet"), sf::Vector2f(50.0f, 100.0f), 0.0f)
{
}

void Scene::update(sf::Time deltaTime)
{
    mSpaceShip.update(deltaTime.asSeconds());
}

void Scene::draw(sf::RenderWindow &window)
{
    mSpaceShip.draw(window);
    mBullet.draw(window);
}
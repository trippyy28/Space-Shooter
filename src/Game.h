#pragma once

#include <SFML/Graphics.hpp>
#include "Circle.h"
#include "SpaceShip.h"
#include "ResourceManager.h"
#include "Scene.h"
#include <vector>
#include <iostream>
#include <algorithm>

class Game
{
public:
    Game();
    void run();

private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();

    float speed = 100.0f;
    float r = 120.0f;
    float g = 160.0f;
    float b = 130.0f;
    sf::Color color = sf::Color(r, g, b);
    sf::RenderWindow mWindow;
    std::vector<Circle> circles;
    ResourceManager mResourceManager;
    std::unique_ptr<Scene> mCurrentScene;
};
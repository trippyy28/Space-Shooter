#include <SFML/Graphics.hpp>
#include "Game.h"

Game::Game() : mWindow(sf::VideoMode({800, 600}), "Nier: Automata")
{
    mWindow.setFramerateLimit(60);

    // Add some circles to the vector
    mResourceManager.loadTexture("SpaceShip", "/users/trippyy28/Desktop/Yaniv Stuff/cmake-sfml-project/src/ship.png");
    mResourceManager.loadTexture("Bullet", "/users/trippyy28/Desktop/Yaniv Stuff/cmake-sfml-project/src/laser.png");
    circles.emplace_back(sf::Vector2f(100.0f, 100.0f));
    circles.emplace_back(sf::Vector2f(200.0f, 200.0f));
    circles.emplace_back(sf::Vector2f(300.0f, 300.0f));
    circles.emplace_back(sf::Vector2f(400.0f, 400.0f));

    mCurrentScene = std::make_unique<Scene>(mResourceManager);
}

void Game::processEvents()
{
    while (const std::optional event = mWindow.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            mWindow.close();
        }
    }
}

void Game::update(sf::Time deltaTime)
{
    for (auto &circle : circles)
    {
        circle.update(deltaTime.asSeconds()); // Update circle logic
    }
    mCurrentScene->update(deltaTime);
}

void Game::render()
{
    mWindow.clear(sf::Color::Red);

    for (auto &circle : circles)
    {
        circle.draw(mWindow);
    }
    mCurrentScene->draw(mWindow);
    mWindow.display();
}

void Game::run()
{
    sf::Clock clock;
    while (mWindow.isOpen())
    {
        sf::Time deltaTime = clock.restart();
        processEvents();
        update(deltaTime);
        render();
    }
}

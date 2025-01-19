#include <SFML/Graphics.hpp>
#include "ResourceManager.h"
#include "SpaceShip.h"
#include "Bullet.h"
class Scene
{

public:
    Scene(ResourceManager &resourceManager);

    void draw(sf::RenderWindow &window);
    void update(sf::Time deltaTime);
    void handleEvent(const sf::Event &event);
    void collisionDetection();

private:
    ResourceManager &mResourceManager;
    // std::vector<Bullets> mBullets;
    sf::Font mFont;
    int mScore = 0;
    SpaceShip mSpaceShip;
    Bullet mBullet;
};
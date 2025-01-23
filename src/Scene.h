#include <SFML/Graphics.hpp>
#include "ResourceManager.h"
#include "SpaceShip.h"
#include "Bullet.h"
#include "Btn.h"
class Scene
{

public:
    Scene(ResourceManager &resourceManager);

    void draw(sf::RenderWindow &window);
    void update(sf::Time deltaTime);
    void handleEvent(const sf::Event &event);
    void collisionDetection();
    void fireBullet(const sf::Vector2f &position);

private:
    ResourceManager &mResourceManager;
    std::vector<Bullet> mBullets;
    sf::Font mFont;
    int mScore = 0;
    SpaceShip mSpaceShip;
    Bullet mBullet;
    Btn mBtn;
};
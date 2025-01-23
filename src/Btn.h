#include "SFML/Graphics.hpp"
#include <iostream>

class Btn
{
public:
    Btn(sf::Vector2f position, sf::Vector2f size);
    void draw(sf::RenderWindow &window) const;
    void update(float deltaTime);

private:
    sf::RectangleShape shape;
    sf::Vector2f velocity = {80.0f, 80.0f};
    float r = 120.0f;
    float g = 253.0f;
    float b = 128.0f;
    sf::Color color = sf::Color(r, g, b);
    sf::Font font;
    sf::Text text;
};
#include "Btn.h"

Btn::Btn(sf::Vector2f position, sf::Vector2f size)
    : color(r, g, b), velocity(80.0f, 80.0f), text(font)
{
    sf::Vector2f textPosition = (position + size) / 2.0f;
    if (!font.openFromFile("/Users/trippyy28/Desktop/Yaniv Stuff/cmake-sfml-project/src/font.ttf"))
    {
        std::cerr << "Error: Font not found!" << std::endl;
    }
    shape.setSize(size);
    shape.setFillColor(color);
    shape.setPosition(position);
    text.setPosition(textPosition);
    text.setFillColor(sf::Color::Black);
}

void Btn::update(float deltaTime)
{
    sf::Vector2f position = shape.getPosition();
    position += velocity * deltaTime;

    shape.setPosition(position);
}

void Btn::draw(sf::RenderWindow &window) const
{
    window.draw(shape);
    window.draw(text);
}
#include "Circle.h"

Circle::Circle(sf::Vector2f position)
    : radius(30.0f), color(r, g, b), velocity(80.0f, 80.0f)
{
    shape.setRadius(radius);
    shape.setFillColor(color);
    shape.setPosition(position);
}

void Circle::draw(sf::RenderWindow &window) const
{
    window.draw(shape);
}

void Circle::update(float deltaTime)
{

    sf::Vector2f position = shape.getPosition();
    position += velocity * deltaTime;

    const float windowWidth = 800;
    const float windowHeight = 600;

    if (position.x < 0) // Collision with the left edge
    {
        position.x = 0;
        velocity.x = -velocity.x;
    }
    else if (position.x + radius * 2 > windowWidth) // Collision with the right edge
    {
        position.x = windowWidth - radius * 2;
        velocity.x = -velocity.x;
    }

    if (position.y < 0) // Collision with the top edge
    {
        position.y = 0;
        velocity.y = -velocity.y;
    }
    else if (position.y + radius * 2 > windowHeight) // Collision with the bottom edge
    {
        position.y = windowHeight - radius * 2;
        velocity.y = -velocity.y;
    }

    shape.setPosition(position);
}

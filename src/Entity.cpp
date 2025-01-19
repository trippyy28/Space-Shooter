#include "Entity.h"

Entity::Entity(const sf::Texture &texture)
    : mSprite(texture)
{
    // Sprite is automatically associated with the passed texture
}

void Entity::draw(sf::RenderWindow &window) const
{
    // Default: draw the sprite
    window.draw(mSprite);
}
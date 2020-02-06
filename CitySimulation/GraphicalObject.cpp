#include "GraphicalObject.h"

GraphicalObject::GraphicalObject(float x, float y, float sizeX, float sizeY, ObjectType _ID, const sf::Texture* _texture) :
	sf::RectangleShape(sf::Vector2f(sizeX,sizeY))
{
	setPosition(x, y);
	ID = _ID;
	setTexture(_texture);
}


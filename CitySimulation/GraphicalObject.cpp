#include "GraphicalObject.h"

GraphicalObject::GraphicalObject(float x, float y, ObjectType _ID, const sf::Texture* _texture)
{
	setPosition(x, y);
	ID = _ID;
	setTexture(_texture);
}

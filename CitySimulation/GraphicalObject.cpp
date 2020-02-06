#include "GraphicalObject.h"

GraphicalObject::GraphicalObject(float x, float y, float sizeX, float sizeY, ObjectType _ID, sf::Texture* _texture) :
	sf::RectangleShape(sf::Vector2f(sizeX,sizeY))
{
	setPosition(x, y);
	ID = _ID;
	usedTexture = _texture;
	setTexture(_texture);
}

GraphicalObject::~GraphicalObject() {
	this->usedTexture->~Texture();
}

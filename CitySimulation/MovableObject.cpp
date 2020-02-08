#include "MovableObject.h"

MovableObject::MovableObject(float x, float y, float sizeX, float sizeY, ObjectType _ID, sf::Texture* _texture) :
	GraphicalObject(x,y,sizeX, sizeY, _ID, _texture)
{
}

MovableObject::~MovableObject()
{
}


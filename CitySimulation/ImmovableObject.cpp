#include "ImmovableObject.h"

ImmovableObject::ImmovableObject(float x, float y, float sizeX, float sizeY, ObjectType _ID, sf::Texture* _texture) :
	GraphicalObject(x, y, sizeX, sizeY, _ID, _texture)
{
}

ImmovableObject::~ImmovableObject() {
}


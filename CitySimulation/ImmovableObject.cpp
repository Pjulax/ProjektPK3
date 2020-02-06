#include "ImmovableObject.h"

ImmovableObject::ImmovableObject(float x, float y, float sizeX, float sizeY, ObjectType _ID, sf::Texture* _texture) :
	GraphicalObject(x, y, sizeX, sizeY, _ID, _texture)
{
}

bool ImmovableObject::HasThisCar(GraphicalObject* queriedCar)
{
	return false;
}

bool ImmovableObject::AddCar(GraphicalObject* Car)
{
	return false;
}

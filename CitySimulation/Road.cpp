#include "Road.h"

Road::Road(float x, float y, sf::Texture* _texture) :
	ImmovableObject(x, y, 128, 64, ObjectType::ROAD, _texture)
{
}

Road::~Road()
{
}

bool Road::HasThisCar(GraphicalObject* queriedCar)
{
	return false;
}

bool Road::AddCar(GraphicalObject* Car)
{
	return false;
}

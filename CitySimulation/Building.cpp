#include "Building.h"

Building::Building(float x, float y, sf::Texture* _texture) :
	ImmovableObject(x, y, 128, 128,ObjectType::BUILDING, _texture)
{
}

Building::~Building()
{
}

bool Building::HasThisCar(GraphicalObject* queriedCar)
{
	return false;
}

bool Building::AddCar(GraphicalObject* Car)
{
	return false;
}

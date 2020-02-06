#include "Crossing.h"

Crossing::Crossing(float x, float y, sf::Texture* _texture) :
	ImmovableObject(x, y, 64, 64, ObjectType::CROSSING, _texture)
{
}

Crossing::~Crossing()
{
}

bool Crossing::HasThisCar(GraphicalObject* queriedCar)
{
	return false;
}

bool Crossing::AddCar(GraphicalObject* Car)
{
	return false;
}

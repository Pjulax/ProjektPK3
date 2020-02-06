#pragma once
#include "ImmovableObject.h"

class Crossing :
	public ImmovableObject
{
public:
	Crossing(float x, float y, sf::Texture* _texture);
	~Crossing();
	bool HasThisCar(GraphicalObject* queriedCar);
	bool AddCar(GraphicalObject* Car);
};


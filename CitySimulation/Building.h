#pragma once
#include "ImmovableObject.h"

class Building :
	public ImmovableObject
{
public:
	Building(float x, float y, sf::Texture* _texture);
		bool HasThisCar(GraphicalObject* queriedCar);
		bool AddCar(GraphicalObject* Car);
	};


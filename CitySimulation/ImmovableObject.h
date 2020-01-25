#pragma once
#include "GraphicalObject.h"
#include <vector>

class ImmovableObject :
	public GraphicalObject
{
private:
	std::vector<GraphicalObject*> CarsContaining;
public:
	ImmovableObject(int XL, int XR, int YU, int YD, ObjectType _ID, sf::Texture _texture);

	virtual bool HasThisCar(GraphicalObject* queriedCar) = 0;
	virtual bool AddCar(GraphicalObject* Car) = 0;
};


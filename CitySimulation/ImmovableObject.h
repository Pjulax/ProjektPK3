#pragma once
#include "GraphicalObject.h"
#include <vector>

class ImmovableObject :
	public GraphicalObject
{
private:
	std::vector<GraphicalObject*> CarsContaining;
public:
	ImmovableObject(int XL, int XR, int YU, int YD, ObjectType _ID);

	virtual bool HasThisCar(GraphicalObject* queriedCar);
	virtual bool AddCar(GraphicalObject* Car);
};


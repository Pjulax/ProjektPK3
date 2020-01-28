#pragma once
#include "GraphicalObject.h"
#include "MovableObject.h"
#include <vector>

class ImmovableObject :
	public GraphicalObject
{
private:
	std::vector<GraphicalObject*> CarsContaining;
public:
	ImmovableObject(float x, float y, ObjectType _ID, sf::Texture* _texture);

	virtual bool HasThisCar(GraphicalObject* queriedCar) = 0;
	virtual bool AddCar(GraphicalObject* Car) = 0;
};

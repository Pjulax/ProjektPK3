#pragma once
#include "GraphicalObject.h"
#include "MovableObject.h"
#include <vector>

class ImmovableObject :
	public GraphicalObject
{
protected:
	std::vector<GraphicalObject*> CarsContaining;
public:
	ImmovableObject(float x, float y, float sizeX, float sizeY, ObjectType _ID, sf::Texture* _texture);
	~ImmovableObject();
	virtual bool HasThisCar(GraphicalObject* queriedCar) = 0;
	virtual bool AddCar(GraphicalObject* Car) = 0;
};

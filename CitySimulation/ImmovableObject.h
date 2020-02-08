#pragma once
#include "GraphicalObject.h"
#include "MovableObject.h"
#include <vector>

/**
* ImmovableObjects base class derived from base class for everything - GraphicalObject
* carsContaining - vector for all cars that now are on object
* 
* 
*/



class ImmovableObject :
	public GraphicalObject
{
public:
	ImmovableObject(float x, float y, float sizeX, float sizeY, ObjectType _ID, sf::Texture* _texture);
	~ImmovableObject();
	virtual bool HasThisCar(GraphicalObject* queriedCar) = 0;
	virtual bool AddCar(GraphicalObject* Car) = 0;

protected:
	std::vector<GraphicalObject*> CarsContaining;
};

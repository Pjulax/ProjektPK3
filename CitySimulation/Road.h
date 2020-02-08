#pragma once
#include "ImmovableObject.h"

class Road :
	public ImmovableObject
{
public:
	Road(float x, float y, sf::Texture* _texture);
	~Road();
	bool HasThisCar(GraphicalObject* queriedCar);
	bool AddCar(GraphicalObject* Car);

private:
	ImmovableObject* next;
	ImmovableObject* prev;

};


#pragma once
#include "Car.h"

class PrivilegedCar :
	public Car
{
public:
	PrivilegedCar(float x, float y, float sizeX, float sizeY, ObjectType _ID, sf::Texture* _texture);
	void moveObj(int speed);
};


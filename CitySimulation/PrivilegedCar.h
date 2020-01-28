#pragma once
#include "Car.h"

class PrivilegedCar :
	public Car
{
public:
	PrivilegedCar(int XL, int XR, int YU, int YD, ObjectType _ID, sf::Texture _texture);
	void move(int speed);
};


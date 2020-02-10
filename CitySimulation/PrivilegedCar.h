#pragma once
#include "Car.h"

class PrivilegedCar : public Car {
public:
	PrivilegedCar(float x, float y, ImmovableObject* _actualFloor, sf::Texture* _texture, float _speed);
	~PrivilegedCar();
};
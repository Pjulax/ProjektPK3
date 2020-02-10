#include "PrivilegedCar.h"

PrivilegedCar::PrivilegedCar(float x, float y, ImmovableObject* _actualFloor, sf::Texture* _texture, float _speed) :
	Car(x, y, _actualFloor, _texture, _speed)
{
}

PrivilegedCar::~PrivilegedCar()
{
}

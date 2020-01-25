#pragma once
#include "ImmovableObject.h"

class Road :
	public ImmovableObject
{
public:
	Road(int XL, int XR, int YU, int YD, ObjectType _ID, sf::Texture _texture);
};


#pragma once
#include "ImmovableObject.h"

class Crossing :
	public ImmovableObject
{
public:
	Crossing(int XL, int XR, int YU, int YD, ObjectType _ID, sf::Texture _texture);
};


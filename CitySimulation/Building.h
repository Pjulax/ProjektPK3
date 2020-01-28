#pragma once
#include "ImmovableObject.h"

class Building :
	public ImmovableObject
{
public:
	Building(int XL, int XR, int YU, int YD, ObjectType _ID, sf::Texture _texture);
};


#include "GraphicalObject.h"

GraphicalObject::GraphicalObject(int XL, int XR, int YU, int YD, ObjectType _ID, sf::Texture _texture)
{
	coordinates[0] = XL;
	coordinates[1] = XR;
	coordinates[2] = YU;
	coordinates[3] = YD;
	ID = _ID;
	texture = _texture;
}

int GraphicalObject::getPosXL()
{
	return this->coordinates[0];
}

int GraphicalObject::getPosXR()
{
	return this->coordinates[1];
}

int GraphicalObject::getPosYU()
{
	return this->coordinates[2];
}

int GraphicalObject::getPosYD()
{
	return this->coordinates[3];
}

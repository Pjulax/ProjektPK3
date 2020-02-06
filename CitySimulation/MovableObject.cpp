#include "MovableObject.h"

MovableObject::MovableObject(float x, float y, float sizeX, float sizeY, ObjectType _ID, sf::Texture* _texture) :
	GraphicalObject(x,y,sizeX, sizeY, _ID, _texture)
{
}

bool MovableObject::isMapEnd(int winSizeX, int winSizeY)
{
	if (this->getPosition().x == 0 || this->getPosition().x == winSizeX
		|| this->getPosition().y == 0 || this->getPosition().y == winSizeY)
		return true;
	else
		return false;
}

#include "MovableObject.h"

bool MovableObject::isMapEnd(int winSizeX, int winSizeY)
{
	if (this->centerX == 0 || this->centerX == winSizeX
		|| this->centerY == 0 || this->centerY == winSizeY)
		return true;
	else
		return false;
}

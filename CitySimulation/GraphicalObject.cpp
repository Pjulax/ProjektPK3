#include "GraphicalObject.h"

GraphicalObject::GraphicalObject(int XL, int XR, int YU, int YD, ObjectType _ID)
{
	coordinates[0] = XL;
	coordinates[1] = XR;
	coordinates[2] = YU;
	coordinates[3] = YD;
	ID = _ID;
}

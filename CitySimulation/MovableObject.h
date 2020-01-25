#pragma once
#include "GraphicalObject.h"
#include "Crossing.h"
#include "Road.h"

class MovableObject :
	public GraphicalObject
{
private:
	ImmovableObject* actualFloor;
	int speed;
protected:

public:
	MovableObject(int XL, int XR, int YU, int YD, ObjectType _ID, sf::Texture _texture);
	bool isMapEnd(int winSizeX, int winSizeY);
	virtual void move() = 0;
	virtual bool onCrossing() = 0;
	virtual int directionGenerate() = 0;
};

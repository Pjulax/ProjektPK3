#pragma once
#include "GraphicalObject.h"

class MovableObject :
	public GraphicalObject
{
private:
	int speed;
public:
	virtual void move();
};

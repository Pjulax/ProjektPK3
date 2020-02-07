#pragma once
#include "GraphicalObject.h"
#include "ImmovableObject.h"

class MovableObject :
	public GraphicalObject
{
public:
	MovableObject(float x, float y, float sizeX, float sizeY, ObjectType _ID, sf::Texture* _texture);
	virtual bool isMapEnd(int winSizeX, int winSizeY) = 0;
	virtual void moveObj() = 0;
	virtual bool onCrossing() = 0;
	virtual int directionGenerate() = 0;
};

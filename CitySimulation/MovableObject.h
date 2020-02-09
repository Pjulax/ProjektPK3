#pragma once
#include "GraphicalObject.h"
#include "ImmovableObject.h"

class ImmovableObject;

class MovableObject :
	public GraphicalObject
{
public:
	MovableObject(float x, float y, float sizeX, float sizeY, ObjectType _ID, sf::Texture* _texture);
	~MovableObject();
	virtual bool isMapEnd(int winSizeX, int winSizeY) = 0;
	virtual void moveObj() = 0;
	virtual bool onCrossing() = 0;
	virtual int directionGenerate() = 0;
	virtual ImmovableObject* getActualFloor() = 0;
	virtual bool isInCrossingQueue() = 0;
	virtual void setActualFloor(ImmovableObject* _actualFloor) = 0;
	virtual void setInCrossingQueue(bool _choice) = 0;
protected:
	ImmovableObject *actualFloor;
	bool inCrossingQueue;
};

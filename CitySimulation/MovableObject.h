#pragma once
#include "GraphicalObject.h"
#include "ImmovableObject.h"

class MovableObject :
	public GraphicalObject
{
private:
	int speed;
protected:

public:
	MovableObject(float x, float y, ObjectType _ID, sf::Texture* _texture);
	bool isMapEnd(int winSizeX, int winSizeY);
	virtual void move() = 0;
	virtual bool onCrossing() = 0;
	virtual int directionGenerate() = 0;
};

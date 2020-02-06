#pragma once
#include "GraphicalObject.h"
#include "ImmovableObject.h"

class MovableObject :
	public GraphicalObject
{
private:

protected:
	float speed;
	int dir;
	int angle;
	int nextDir;
	double remainAngle;
public:
	MovableObject(float x, float y, float sizeX, float sizeY, ObjectType _ID, sf::Texture* _texture);
	bool isMapEnd(int winSizeX, int winSizeY);
	virtual void moveObj() = 0;
	virtual bool onCrossing() = 0;
	virtual int directionGenerate() = 0;
};

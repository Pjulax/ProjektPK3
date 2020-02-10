#pragma once
#include "GraphicalObject.h"
#include "ImmovableObject.h"

class ImmovableObject;

class MovableObject :
	public GraphicalObject
{
public:
	MovableObject(float x, float y, float sizeX, float sizeY, ObjectType _ID, sf::Texture* _texture, float _speed);
	~MovableObject();

	virtual void moveObj() = 0;
	virtual bool isMapEnd(int winSizeX, int winSizeY) = 0;
	virtual bool isInCrossingQueue() = 0;
	virtual bool isMovingOnCrossing() = 0;
	virtual bool isCollisionAlert() = 0;
	virtual bool onCrossing() = 0;
	virtual ImmovableObject* getActualFloor() = 0;
	virtual int getRotationRemaining() = 0;
	virtual void setActualFloor(ImmovableObject* _actualFloor) = 0;
	virtual void setInCrossingQueue(bool _choice) = 0;
	virtual void setMovingOnCrossing(bool _choice) = 0;
	virtual void setCollisionAlert(bool _choice) = 0;
	virtual void setRotationRemaining() = 0;
protected:
	virtual int directionGenerate() = 0;
	ImmovableObject *actualFloor;
	bool inCrossingQueue;
	bool movingOnCrossing;
	bool collisionAlert;
	int dir;
	double rotationRemaining;
	int remainingStraight;
	float speed;
};

#pragma once
#include "MovableObject.h"
#include <iostream>
#include <cmath>
#include <cstdlib>

class Car :
	public MovableObject
{
public:
	Car(float x, float y, ImmovableObject* _actualFloor, sf::Texture* _texture, float _speed);
	~Car();

	void moveObj();
	bool isMapEnd(int winSizeX, int winSizeY);
	bool isInCrossingQueue();
	bool isMovingOnCrossing();
	bool isCollisionAlert();
	bool onCrossing();
	ImmovableObject* getActualFloor();
	int getRotationRemaining();
	void setActualFloor(ImmovableObject* _actualFloor);
	void setInCrossingQueue(bool _choice);
	void setMovingOnCrossing(bool _choice);
	void setCollisionAlert(bool _choice);
	void setRotationRemaining();
private:
	int directionGenerate();
};


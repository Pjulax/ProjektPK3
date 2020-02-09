#pragma once
#include "MovableObject.h"
#include <iostream>
#include <cmath>
#include <cstdlib>

class Car :
	public MovableObject
{
public:
	Car(float x, float y, ImmovableObject* _actualFloor, sf::Texture* _texture);
	~Car();
	bool isMapEnd(int winSizeX, int winSizeY);
	void moveObj();
	bool onCrossing();
	int directionGenerate();
	ImmovableObject* getActualFloor();
	bool isInCrossingQueue();
	void setActualFloor(ImmovableObject* _actualFloor);
	void setInCrossingQueue(bool _choice);

private:

};


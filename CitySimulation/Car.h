#pragma once
#include "MovableObject.h"

class Car :
	public MovableObject
{
public:
	Car(int XL, int XR, int YU, int YD, ObjectType _ID, sf::Texture _texture);
	virtual void move();
	//bool isMapEnd(int winSizeX, int winSizeY);
	bool onCrossing();
	int directionGenerate();

};


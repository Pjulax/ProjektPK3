#pragma once
#include "MovableObject.h"

class Car :
	public MovableObject
{
public:
	Car(float x, float y, ObjectType _ID, sf::Texture* _texture);
	virtual void move();
	//bool isMapEnd(int winSizeX, int winSizeY);
	bool onCrossing();
	int directionGenerate();

};


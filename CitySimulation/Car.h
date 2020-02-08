#pragma once
#include "MovableObject.h"
#include <iostream>
#include <cmath>

class Car :
	public MovableObject
{
public:
	Car(float x, float y, sf::Texture* _texture);
	~Car();
	bool isMapEnd(int winSizeX, int winSizeY);
	void moveObj();
	bool onCrossing();
	int directionGenerate();

private:

};


#pragma once
#include "MovableObject.h"

class Car :
	public MovableObject
{
private:

public:
	Car(float x, float y, float sizeX, float sizeY, sf::Texture* _texture);
	~Car();
	bool isMapEnd(int winSizeX, int winSizeY);
	void moveObj();
	bool isMapEnd(int winSizeX, int winSizeY);
	bool onCrossing();
	int directionGenerate();

};


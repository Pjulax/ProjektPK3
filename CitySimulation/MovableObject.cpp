#include "MovableObject.h"

MovableObject::MovableObject(float x, float y, float sizeX, float sizeY, ObjectType _ID, sf::Texture* _texture, float _speed) :
	GraphicalObject(x,y,sizeX, sizeY, _ID, _texture)
{

	this->actualFloor = nullptr;
	this->inCrossingQueue = false;
	this->movingOnCrossing = false;
	this->collisionAlert = false;
	this->dir = false;
	this->rotationRemaining = 0.0;
	this->remainingStraight = 0;
	this->speed = _speed;
}

MovableObject::~MovableObject()
{
}
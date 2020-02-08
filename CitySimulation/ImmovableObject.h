#pragma once
#include "GraphicalObject.h"
#include "MovableObject.h"
#include <vector>

/**
* ImmovableObjects base class derived from base class for everything - GraphicalObject
* carsContaining - vector for all cars that now are on object
* 
* 
*/



class ImmovableObject :
	public GraphicalObject
{
public:
	ImmovableObject(float x, float y, float sizeX, float sizeY, ObjectType _ID, sf::Texture* _texture);
	~ImmovableObject();

	virtual void setNext(ImmovableObject* next) = 0;
	virtual void setPrev(ImmovableObject* prev) = 0;
	virtual void setLeft(ImmovableObject* left) = 0;
	virtual void setRight(ImmovableObject* right) = 0;
	virtual void setUpper(ImmovableObject* upper) = 0;
	virtual void setLower(ImmovableObject* lower) = 0;
	virtual ImmovableObject* getNext() = 0;
	virtual ImmovableObject* getPrev() = 0;
	virtual ImmovableObject* getLeft() = 0;
	virtual ImmovableObject* getRight() = 0;
	virtual ImmovableObject* getUpper() = 0;
	virtual ImmovableObject* getLower() = 0;

protected:
	ImmovableObject		*left,
						*right,
						*upper,
						*lower;
};

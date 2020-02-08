#pragma once
#include "ImmovableObject.h"

class Road :
	public ImmovableObject
{
public:
	Road(float x, float y, sf::Texture* _texture);
	~Road();

	void setNext(ImmovableObject* next);
	void setPrev(ImmovableObject* prev);
	void setLeft(ImmovableObject* left);
	void setRight(ImmovableObject* right);
	void setUpper(ImmovableObject* upper);
	void setLower(ImmovableObject* lower);
	ImmovableObject* getNext();
	ImmovableObject* getPrev();
	ImmovableObject* getLeft();
	ImmovableObject* getRight();
	ImmovableObject* getUpper();
	ImmovableObject* getLower();

private:

};


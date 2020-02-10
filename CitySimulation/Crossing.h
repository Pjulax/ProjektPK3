#pragma once
#include "ImmovableObject.h"

class Crossing :
	public ImmovableObject
{
public:
	Crossing(float x, float y, sf::Texture* _texture);
	~Crossing();
	void setNext(ImmovableObject* next);
	void setPrev(ImmovableObject* prev);
	void setLeft(ImmovableObject* left);
	void setRight(ImmovableObject* right);
	void setUpper(ImmovableObject* upper);
	void setLower(ImmovableObject* lower);
	void setBusy(bool _inUse);
	ImmovableObject* getNext();
	ImmovableObject* getPrev();
	ImmovableObject* getLeft();
	ImmovableObject* getRight();
	ImmovableObject* getUpper();
	ImmovableObject* getLower();
	bool isBusy();
private:
	ImmovableObject* next = nullptr;
	ImmovableObject* prev = nullptr;
};


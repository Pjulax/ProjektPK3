#pragma once
#include "ImmovableObject.h"

class Building :
	public ImmovableObject
{
public:
	Building(float x, float y, sf::Texture* _texture);
	~Building();
	bool HasThisCar(GraphicalObject* queriedCar);
	bool AddCar(GraphicalObject* Car);
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
	};
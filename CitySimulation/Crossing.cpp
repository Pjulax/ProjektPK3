#include "Crossing.h"

Crossing::Crossing(float x, float y, sf::Texture* _texture) :
	ImmovableObject(x, y, 64, 64, ObjectType::CROSSING, _texture)
{
	this->next = nullptr;
	this->prev = nullptr;
}

Crossing::~Crossing()
{
}

void Crossing::setNext(ImmovableObject* next)
{
}

void Crossing::setPrev(ImmovableObject* prev)
{
}

void Crossing::setLeft(ImmovableObject* left)
{
	this->left = left;
}

void Crossing::setRight(ImmovableObject* right)
{
	this->right = right;
}

void Crossing::setUpper(ImmovableObject* upper)
{
	this->upper = upper;
}

void Crossing::setLower(ImmovableObject* lower)
{
	this->lower = lower;
}

void Crossing::setBusy(bool _inUse)
{
	this->busy = _inUse;
}

ImmovableObject* Crossing::getNext()
{
	return nullptr;
}

ImmovableObject* Crossing::getPrev()
{
	return nullptr;
}

ImmovableObject* Crossing::getLeft()
{
	return this->left;
}

ImmovableObject* Crossing::getRight()
{
	return this->right;
}

ImmovableObject* Crossing::getUpper()
{
	return this->upper;
}

ImmovableObject* Crossing::getLower()
{
	return this->lower;
}

bool Crossing::isBusy()
{
	return this->busy;
}

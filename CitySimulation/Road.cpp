#include "Road.h"

Road::Road(float x, float y, sf::Texture* _texture) :
	ImmovableObject(x, y, 128, 64, ObjectType::ROAD, _texture)
{
	this->left = nullptr;
	this->right = nullptr;
	this->upper = nullptr;
	this->lower = nullptr;
}

Road::~Road()
{
}

void Road::setNext(ImmovableObject* next)
{
	if (this->getRotation() == 0) {
		this->right = next;
	}
	else {
		this->lower = next;
	}
}

void Road::setPrev(ImmovableObject* prev)
{
	if (this->getRotation() == 0) {
		this->left = prev;
	}
	else {
		this->upper = prev;
	}
}

void Road::setLeft(ImmovableObject* left)
{
}

void Road::setRight(ImmovableObject* right)
{
}

void Road::setUpper(ImmovableObject* upper)
{
}

void Road::setLower(ImmovableObject* lower)
{
}

ImmovableObject* Road::getNext()
{
	if (this->getRotation() == 0) {
		return this->right;
	}
	else {
		return this->lower;
	}
}

ImmovableObject* Road::getPrev()
{
	if (this->getRotation() == 0) {
		return this->left;
	}
	else {
		return this->upper;
	}
}

ImmovableObject* Road::getLeft()
{
	return this->left;
}

ImmovableObject* Road::getRight()
{
	return this->right;
}

ImmovableObject* Road::getUpper()
{
	return this->upper;
}

ImmovableObject* Road::getLower()
{
	return this->lower;
}

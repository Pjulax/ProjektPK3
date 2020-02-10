#include "Building.h"

Building::Building(float x, float y, sf::Texture* _texture) :
	ImmovableObject(x, y, 128, 128,ObjectType::BUILDING, _texture)
{
}

Building::~Building()
{
}

void Building::setNext(ImmovableObject* next)
{
}

void Building::setPrev(ImmovableObject* prev)
{
}

void Building::setLeft(ImmovableObject* left)
{
}

void Building::setRight(ImmovableObject* right)
{
}

void Building::setUpper(ImmovableObject* upper)
{
}

void Building::setLower(ImmovableObject* lower)
{
}

void Building::setBusy(bool _inUse)
{
}

ImmovableObject* Building::getNext()
{
	return nullptr;
}

ImmovableObject* Building::getPrev()
{
	return nullptr;
}

ImmovableObject* Building::getLeft()
{
	return nullptr;
}

ImmovableObject* Building::getRight()
{
	return nullptr;
}

ImmovableObject* Building::getUpper()
{
	return nullptr;
}

ImmovableObject* Building::getLower()
{
	return nullptr;
}

bool Building::isBusy()
{
	return false;
}

#include "ImmovableObject.h"

ImmovableObject::ImmovableObject(float x, float y, float sizeX, float sizeY, ObjectType _ID, sf::Texture* _texture) :
	GraphicalObject(x, y, sizeX, sizeY, _ID, _texture)
{
	this->left = nullptr;
	this->right = nullptr;
	this->upper = nullptr;
	this->lower = nullptr;
	this->busy = false;
}

ImmovableObject::~ImmovableObject() {
}


#include "Car.h"
#include <cmath>
Car::Car(float x, float y, float sizeX, float sizeY, sf::Texture* _texture) :
    MovableObject(x, y, sizeX, sizeY, ObjectType::CAR, _texture)
{
}

Car::~Car() 
{
}

void Car::moveObj()
{
	//if (dir == 0 && angle == 0) {
	//	this->move(sf::Vector2f(speed * timeDelayed,0.0f);
	//}
	//else if (dir == 1 && angle == 0) {

	//	this->move(sf::Vector2f(std::cos() * timeDelayed, std::sin();
	//}
}
//bool Car::isMapEnd(int winSizeX, int winSizeY)
//{
//    return false;
//}

bool Car::onCrossing()
{
    return false;
}

int Car::directionGenerate()
{
    return 0;
}

bool Car::isMapEnd(int winSizeX, int winSizeY)
{
	if (this->getPosition().x == 0 || this->getPosition().x == winSizeX
		|| this->getPosition().y == 0 || this->getPosition().y == winSizeY)
		return true;
	else
		return false;
}
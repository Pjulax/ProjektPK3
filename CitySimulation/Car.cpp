#include "Car.h"

Car::Car(float x, float y, ImmovableObject* _actualFloor, sf::Texture* _texture) :
    MovableObject(x, y, 32, 16 , ObjectType::CAR, _texture)
{
	this->actualFloor = _actualFloor;
}

Car::~Car() 
{
	std::cout << "Car is destroyed" << std::endl;
}

void Car::moveObj()
{
	if (this->getRotation() == 0) {
		this->move(sf::Vector2f(1, 0));
	}
	else if (this->getRotation() == 90) {
		this->move(sf::Vector2f(0, 1));
	}
	else if (this->getRotation() == 180) {
		this->move(sf::Vector2f(-1, 0));
	}
	else if (this->getRotation() == 270) {
		this->move(sf::Vector2f(0,-1));
	}
	//if (dir == 0 && angle == 0) {
	//	this->move(sf::Vector2f(speed * timeDelayed,0.0f);
	//}
	//else if (dir == 1 && angle == 0) {

	//	this->move(sf::Vector2f(std::cos() * timeDelayed, std::sin();
	//}
}

bool Car::onCrossing()
{
	if (this->getRotation() == 0) {
		if (this->actualFloor->getRight() != nullptr && this->getGlobalBounds().intersects(this->actualFloor->getRight()->getGlobalBounds())) {
			return true;
		}
	}
	else if (this->getRotation() == 90) {
		if (this->actualFloor->getLower() != nullptr && this->getGlobalBounds().intersects(this->actualFloor->getLower()->getGlobalBounds())) {
			return true;
		}
	}
	else if (this->getRotation() == 180) {
		if (this->actualFloor->getLeft() != nullptr && this->getGlobalBounds().intersects(this->actualFloor->getLeft()->getGlobalBounds())) {
			return true;
		}
	}
	else if (this->getRotation() == 270) {
		if (this->actualFloor->getUpper() != nullptr && this->getGlobalBounds().intersects(this->actualFloor->getUpper()->getGlobalBounds())) {
			return true;
		}
	}
	return false;
}

int Car::directionGenerate()
{
	srand(time(0));
    return rand()%3;
}

ImmovableObject* Car::getActualFloor()
{
	return nullptr;
}

bool Car::isInCrossingQueue()
{
	return false;
}

void Car::setActualFloor(ImmovableObject* _actualFloor)
{
}

void Car::setInCrossingQueue(bool _choice)
{
}

bool Car::isMapEnd(int winSizeX, int winSizeY)
{
	if (this->getPosition().x == -16 || this->getPosition().x == winSizeX + 16
		|| this->getPosition().y == -16 || this->getPosition().y == winSizeY + 16)
		return true;
	else
		return false;
}
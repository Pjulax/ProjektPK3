#include "Car.h"

Car::Car(float x, float y, sf::Texture* _texture) :
    MovableObject(x, y, 32, 16 , ObjectType::CAR, _texture)
{
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
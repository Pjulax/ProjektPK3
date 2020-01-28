#include "Car.h"
Car::Car(float x, float y, ObjectType _ID, sf::Texture* _texture) :
    MovableObject(x,y,_ID, _texture)
{
}

void Car::move()
{

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
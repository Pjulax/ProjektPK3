#include "Car.h"

Car::Car(float x, float y, ImmovableObject* _actualFloor, sf::Texture* _texture, float _speed) :
    MovableObject(x, y, 32, 16 , ObjectType::CAR, _texture, _speed)
{
	this->actualFloor = _actualFloor;
}

Car::~Car() 
{
	std::cout << "Car is destroyed" << std::endl;
}

void Car::moveObj()
{
	if (this->isMovingOnCrossing()) {
        if (this->rotationRemaining == 0 && this->dir == 0) { // Jazda prosto
            if (this->remainingStraight == 0)
                this->remainingStraight = 64;
            else if (this->remainingStraight > 0) {
                this->remainingStraight -= this->speed;

                if (this->getRotation() == 0) {
                    this->move(sf::Vector2f(this->speed, 0));
                    if (this->remainingStraight == 0) {
                        this->actualFloor->getNext()->setBusy(false);
                        this->setActualFloor(this->actualFloor->getNext()->getRight());
                        this->dir = -1;
                        this->setMovingOnCrossing(false);
                    }
                }
                else if (this->getRotation() == 90) {
                    this->move(sf::Vector2f(0, this->speed));
                    if (this->remainingStraight == 0) {
                        this->actualFloor->getNext()->setBusy(false);
                        this->setActualFloor(this->actualFloor->getNext()->getLower());
                        this->dir = -1;
                        this->setMovingOnCrossing(false);
                    }
                }
                else if (this->getRotation() == 180) {
                    this->move(sf::Vector2f((-1)* this->speed, 0));
                    if (this->remainingStraight == 0) {
                        this->actualFloor->getPrev()->setBusy(false);
                        this->setActualFloor(this->actualFloor->getPrev()->getLeft());
                        this->dir = -1;
                        this->setMovingOnCrossing(false);
                    }
                }
                else if (this->getRotation() == 270) {
                    this->move(sf::Vector2f(0, (-1)* this->speed));
                    if (this->remainingStraight == 0) {
                        this->actualFloor->getPrev()->setBusy(false);
                        this->setActualFloor(this->actualFloor->getPrev()->getUpper());
                        this->dir = -1;
                        this->setMovingOnCrossing(false);
                    }
                }
            }
        }
        else if (this->rotationRemaining == 0 && this->dir == 1) { // Jazda prosto
            if (this->remainingStraight == 0)
                this->remainingStraight = 16;
            else if (this->remainingStraight > 0) {
                this->remainingStraight -= this->speed;

                if (this->getRotation() == 90) {
                    this->move(sf::Vector2f(0, this->speed));
                    if (this->remainingStraight == 0) {
                        this->actualFloor->getNext()->setBusy(false);
                        this->setActualFloor(this->actualFloor->getNext()->getLower());
                        this->dir = -1;
                        this->setMovingOnCrossing(false);
                    }
                }

                else if (this->getRotation() == 180) {
                    this->move(sf::Vector2f((-1)* this->speed, 0));
                    if (this->remainingStraight == 0) {
                        this->actualFloor->getNext()->setBusy(false);
                        this->setActualFloor(this->actualFloor->getNext()->getLeft());
                        this->dir = -1;
                        this->setMovingOnCrossing(false);
                    }
                }
                    
                else if (this->getRotation() == 270) {
                    this->move(sf::Vector2f(0, (-1)*this->speed));
                    if (this->remainingStraight == 0) {
                        this->actualFloor->getPrev()->setBusy(false);
                        this->setActualFloor(this->actualFloor->getPrev()->getUpper());
                        this->dir = -1;
                        this->setMovingOnCrossing(false);
                    }
                }

                else if (this->getRotation() == 0) {
                    this->move(sf::Vector2f(this->speed, 0));
                    if (this->remainingStraight == 0) {
                        this->actualFloor->getPrev()->setBusy(false);
                        this->setActualFloor(this->actualFloor->getPrev()->getRight());
                        this->dir = -1;
                        this->setMovingOnCrossing(false);
                    }
                }
                
            }
        }
        else if (this->rotationRemaining == 0 && this->dir == 2) { // Jazda prosto
            if (this->remainingStraight == 0)
                this->remainingStraight = 64;
            else if (this->remainingStraight > 0) {
                this->remainingStraight -= this->speed;
                
                if (this->getRotation() == 0) {
                    this->move(sf::Vector2f(this->speed, 0));
                    if (this->remainingStraight == 0) {
                        this->actualFloor->getNext()->setBusy(false);
                        this->setActualFloor(this->actualFloor->getNext()->getRight());
                        this->dir = -1;
                        this->setMovingOnCrossing(false);
                    }
                }

                else if (this->getRotation() == 90) {
                    this->move(sf::Vector2f(0, this->speed));
                    if (this->remainingStraight == 0) {
                        this->actualFloor->getPrev()->setBusy(false);
                        this->setActualFloor(this->actualFloor->getPrev()->getLower());
                        this->dir = -1;
                        this->setMovingOnCrossing(false);
                    }
                }

                else if (this->getRotation() == 180) {
                    this->move(sf::Vector2f((-1)* this->speed, 0));
                    if (this->remainingStraight == 0) {
                        this->actualFloor->getPrev()->setBusy(false);
                        this->setActualFloor(this->actualFloor->getPrev()->getLeft());
                        this->dir = -1;
                        this->setMovingOnCrossing(false);
                    }
                }

                else if (this->getRotation() == 270) {
                    this->move(sf::Vector2f(0, (-1)* this->speed));
                    if (this->remainingStraight == 0) {
                        this->actualFloor->getNext()->setBusy(false);
                        this->setActualFloor(this->actualFloor->getNext()->getUpper());
                        this->dir = -1;
                        this->setMovingOnCrossing(false);
                    }
                }

            }
        }
        else if (this->rotationRemaining > 0 ) { // SKRETY W PRAWO
            if (this->getRotation() >= 0 && this->getRotation() < 90) { // Trasa LEFT -> LOWER
                if (this->getRotation() == 0) { // Dojazd do linii
                    if (this->remainingStraight == 0) 
                        this->remainingStraight = 15; // Wpis trasy dojazdu
                    else { // jeœli ju¿ wpisane
                        this->remainingStraight -= 1; // jedna przejechana
                            if (this->remainingStraight == 0) {
                                this->move(sf::Vector2f(1, 0)); // dojedz 16 piksel
                                this->rotate(5.625);            // rozpocznij obrot
                                this->rotationRemaining -= 5.625; 
                            }
                    }
                    this->move(sf::Vector2f(1, 0));
                }
                else {
                    this->rotate(5.625);
                    this->rotationRemaining -= 5.625;
                    this->move(sf::Vector2f(1, 1));

                }
            }
            else if (this->getRotation() >= 90 && this->getRotation() < 180) { // Trasa UPPER -> LEFT
                if (this->getRotation() == 90) {
                    if (this->remainingStraight == 0)
                        this->remainingStraight = 15;
                    else {
                        this->remainingStraight -= 1;
                            if (this->remainingStraight == 0) {
                                this->move(sf::Vector2f(0, 1));
                                this->rotate(5.625); 
                                this->rotationRemaining -= 5.625;
                            }
                    }
                    this->move(sf::Vector2f(0, 1));
                }
                else {
                    this->rotate(5.625); 
                    this->rotationRemaining -= 5.625;
                    this->move(sf::Vector2f(-1, 1));

                }
            }
            else if (this->getRotation() >= 180 && this->getRotation() < 270) { // Trasa RIGHT -> UPPER
                if (this->getRotation() == 180) {
                    if (this->remainingStraight == 0)
                        this->remainingStraight = 15;
                    else {
                        this->remainingStraight -= 1;
                            if (this->remainingStraight == 0) {
                                this->move(sf::Vector2f(-1, 0));
                                this->rotate(5.625); 
                                this->rotationRemaining -= 5.625;
                            }
                    }
                    this->move(sf::Vector2f(-1, 0));
                }
                else {
                    this->rotate(5.625); 
                    this->rotationRemaining -= 5.625;
                    this->move(sf::Vector2f(-1, -1));

                }
            }
            else if (this->getRotation() >= 270 && this->getRotation() < 360) { // Trasa  LOWER -> RIGHT
                if (this->getRotation() == 270) {
                    if (this->remainingStraight == 0)
                        this->remainingStraight = 15;
                    else {
                        this->remainingStraight -= 1;
                            if (this->remainingStraight == 0) {
                                this->move(sf::Vector2f(0, -1));
                                this->rotate(5.625); 
                                this->rotationRemaining -= 5.625;
                            }
                    }
                    this->move(sf::Vector2f(0, -1));
                }
                else {
                    this->rotate(5.625); 
                    this->rotationRemaining -= 5.625;
                    this->move(sf::Vector2f(1, -1));
                            
                }
            }
        }
        else if (this->rotationRemaining < 0 ) { // SKRETY W LEWO
            if (this->getRotation() > 0 && this->getRotation() <= 90) { // Trasa UPPER -> RIGHT
                if (this->getRotation() == 90) {
                    if (this->remainingStraight == 0)
                        this->remainingStraight = 47; // wyznacz dojazd na srodek
                else {
                    this->remainingStraight -= 1;
                    if (this->remainingStraight == 0) {
                        this->move(sf::Vector2f(0, 1));
                        this->rotate(-5.625); 
                        this->rotationRemaining += 5.625;
                    }
                }
                this->move(sf::Vector2f(0, 1));
                }
                else {
                    this->rotate(-5.625); 
                    this->rotationRemaining += 5.625;
                    this->move(sf::Vector2f(1, 1));

                }
            }
            else if (this->getRotation() > 90 && this->getRotation() <= 180) { // Trasa RIGHT -> LOWER
                if (this->getRotation() == 180) {
                    if (this->remainingStraight == 0)
                        this->remainingStraight = 47;
                    else {
                        this->remainingStraight -= 1;
                            if (this->remainingStraight == 0) {
                                this->move(sf::Vector2f(-1, 0));
                                this->rotate(-5.625); 
                                this->rotationRemaining += 5.625;
                            }
                    }
                    this->move(sf::Vector2f(-1, 0));
                }
                else {
                    this->rotate(-5.625); 
                    this->rotationRemaining += 5.625;
                    this->move(sf::Vector2f(-1, 1));

                }
            }
            else if (this->getRotation() > 180 && this->getRotation() <= 270) { // Trasa LOWER -> LEFT
                if (this->getRotation() == 270) {
                    if (this->remainingStraight == 0)
                        this->remainingStraight = 47;
                    else {
                        this->remainingStraight -= 1;
                        if (this->remainingStraight == 0) {
                            this->move(sf::Vector2f(0, -1));
                            this->rotate(-5.625); 
                            this->rotationRemaining += 5.625;
                        }
                    }
                    this->move(sf::Vector2f(0, -1));
                }
                else {
                    this->rotate(-5.625); 
                    this->rotationRemaining += 5.625;
                    this->move(sf::Vector2f(-1, -1));

                }
            }
            else if ((this->getRotation() > 270 && (this->getRotation() < 360) || this->getRotation() == 0)) { // Trasa LEFT -> UPPER
                if (this->getRotation() == 0) {
                    if (this->remainingStraight == 0)
                        this->remainingStraight = 47;
                    else {
                        this->remainingStraight -= 1;
                        if (this->remainingStraight == 0) {
                            this->move(sf::Vector2f(1, 0));
                            this->rotate(-5.625);
                            this->rotationRemaining += 5.625;
                        }
                    }
                    this->move(sf::Vector2f(1, 0));
                }
                else {
                    this->rotate(-5.625);
                    this->rotationRemaining += 5.625;
                    this->move(sf::Vector2f(1, -1));

                }
            }
        }
        
	}
	else if (this->isInCrossingQueue()){
		// no move
	}
	else if (this->isCollisionAlert()) {
		// no move
		this->setCollisionAlert(false);
	}
	else {
		if (this->getRotation() == 0) {
			this->move(sf::Vector2f(this->speed, 0));
		}
		else if (this->getRotation() == 90) {
			this->move(sf::Vector2f(0, this->speed));
		}
		else if (this->getRotation() == 180) {
			this->move(sf::Vector2f((-1)* this->speed, 0));
		}
		else if (this->getRotation() == 270) {
			this->move(sf::Vector2f(0, (-1)* this->speed));
		}
	}

	
}
// works
bool Car::onCrossing()
{
	if (this->getRotation() == 0) {
		if (this->actualFloor->getNext() != nullptr && this->getGlobalBounds().intersects(this->actualFloor->getNext()->getGlobalBounds())) {
            //std::cout << "onCrossing()" << std::endl;
			return true;
		}
	}
	else if (this->getRotation() == 90) {
		if (this->actualFloor->getNext() != nullptr && this->getGlobalBounds().intersects(this->actualFloor->getNext()->getGlobalBounds())) {
            //std::cout << "onCrossing()" << std::endl;
			return true;
		}
	}
	else if (this->getRotation() == 180) {
		if (this->actualFloor->getPrev() != nullptr && this->getGlobalBounds().intersects(this->actualFloor->getPrev()->getGlobalBounds())) {
            //std::cout << "onCrossing()" << std::endl;
			return true;
		}
	}
	else if (this->getRotation() == 270) {
		if (this->actualFloor->getPrev() != nullptr && this->getGlobalBounds().intersects(this->actualFloor->getPrev()->getGlobalBounds())) {
            //std::cout << "onCrossing()" << std::endl;
			return true;
		}
	}
	return false;
}

ImmovableObject* Car::getActualFloor()
{
	return this->actualFloor;
}

int Car::getRotationRemaining()
{
	return this->rotationRemaining;
}

bool Car::isInCrossingQueue()
{
	return this->inCrossingQueue;
}

bool Car::isMovingOnCrossing()
{
	return this->movingOnCrossing;
}

bool Car::isCollisionAlert()
{
	return this->collisionAlert;
}

void Car::setActualFloor(ImmovableObject* _actualFloor)
{
	this->actualFloor = _actualFloor;
}

void Car::setInCrossingQueue(bool _choice)
{
	this->inCrossingQueue = _choice;
}

void Car::setMovingOnCrossing(bool _choice)
{
	this->movingOnCrossing = _choice;
}

void Car::setCollisionAlert(bool _choice)
{
	this->collisionAlert = _choice;
}

int Car::directionGenerate()
{
	srand(time(0));
	return rand() % 3;
}

void Car::setRotationRemaining()
{
	this->dir = directionGenerate();
	if (dir == 0) {
		this->rotationRemaining = 0;
	}
	else if (dir == 1) {
		this->rotationRemaining = 90;
	}
	else if (dir == 2) {
		this->rotationRemaining = -90;
	}
}

bool Car::isMapEnd(int winSizeX, int winSizeY)
{
	if (this->getPosition().x == -16 || this->getPosition().x == winSizeX + 16
		|| this->getPosition().y == -16 || this->getPosition().y == winSizeY + 16)
		return true;
	else
		return false;
}
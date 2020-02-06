#pragma once
//C++ Libraries
#include <iostream>
#include <vector>
//SFML Libraries
#include <SFML/Graphics.hpp>
//Classes implemented
#include "GraphicalObject.h"
#include "PrivilegedCar.h"
#include "Building.h"
#include "Road.h"
#include "Crossing.h"


class Manager
{
private:
	std::vector<MovableObject*> Cars;
	std::vector<ImmovableObject*> Roads;
	std::vector<ImmovableObject*> Buildings;
	std::vector<ImmovableObject*> Crossings;
	int xCrossAmount = -1;
	int yCrossAmount = -1;
	bool checkCollision(); // checks collision on coordinates
	bool generateMap();
public:
	Manager();
	Manager(int _xCrossAmount, int _yCrossAmount);
	int RunApplication();
	bool moveCars(); // moves cars with conditions for crossing, privilege, collision

};

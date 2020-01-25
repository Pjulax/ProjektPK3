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
	bool checkCollision(); // checks collision on coordinates

public:
	Manager();
	Manager(std::vector<GraphicalObject*> _Cars, std::vector<GraphicalObject*> _Roads, std::vector<GraphicalObject*> _Buildings, std::vector<GraphicalObject*> _Crossings);
	int RunApplication();
	bool moveCars(); // moves cars with conditions for crossing, privilege, collision

};

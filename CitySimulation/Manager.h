#pragma once
//C++ Libraries
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
//SFML Libraries
#include <SFML/Graphics.hpp>
//Classes implemented
#include "GraphicalObject.h"
#include "Car.h"
#include "Building.h"
#include "Road.h"
#include "Crossing.h"


class Manager
{

public:
	Manager();
	Manager(int _xCrossAmount, int _yCrossAmount);
	void RunApplication();
	bool moveCars(int winXsize, int winYsize); // moves cars with conditions for crossing, privilege, collision

private:
	std::vector<MovableObject*> Cars;
	std::vector<ImmovableObject*> Roads;
	std::vector<ImmovableObject*> Buildings;
	std::vector<ImmovableObject*> Crossings;
	int xCrossAmount = -1;
	int yCrossAmount = -1;
	bool fileLoaded = false;
	bool checkCollision(); // checks collision on coordinates
	void generateMap();
	void generateBuildings();
	void generateRoads();
	void generateCrossings();
	void generateCars();
	void linkingRoads();
};

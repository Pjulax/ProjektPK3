#pragma once
#include <vector>
#include "GraphicalObject.h"

class Manager
{
private:
	std::vector<GraphicalObject*> Cars;
	std::vector<GraphicalObject*> Roads;
	std::vector<GraphicalObject*> Buildings;
	std::vector<GraphicalObject*> Crossings;
	bool checkCollision(); // checks collision on coordinates

public:
	Manager(std::vector<GraphicalObject*> _Cars, std::vector<GraphicalObject*> _Roads, std::vector<GraphicalObject*> _Buildings, std::vector<GraphicalObject*> _Crossings);

	bool moveCars(); // moves cars with conditions for crossing, privilege, collision

};

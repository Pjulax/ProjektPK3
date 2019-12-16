#pragma once
enum ObjectType {Car, PrivilegedCar, Crossing, Road, Building};

class GraphicalObject
{
private:
	int coordinates[4];
	ObjectType ID;
	// SFML TEXTURE
public:
	GraphicalObject(int XL, int XR, int YU, int YD, ObjectType _ID);
};


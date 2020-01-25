#pragma once
#include <SFML/Graphics.hpp>

enum class ObjectType {UNIDENTIFIED, CAR, PRILIVEGEDCAR, CROSSING, ROAD, BUILDING};

class GraphicalObject
{
private:
	int coordinates[4];
	ObjectType ID;
	sf::Texture texture;
public:
	GraphicalObject(int XL, int XR, int YU, int YD, ObjectType _ID, sf::Texture _texture);
	void DrawObject();
	int getPosXL();
	int getPosXR();
	int getPosYU();
	int getPosYD();
	void setPos(int changePosXL, int changePosXR, int changePosYU, int changePosYD);
};
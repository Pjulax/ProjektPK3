#pragma once
#include <SFML/Graphics.hpp>

enum class ObjectType {UNIDENTIFIED, CAR, PRILIVEGEDCAR, CROSSING, ROAD, BUILDING};

class GraphicalObject :
	public sf::RectangleShape
{
private:
	ObjectType ID;
	
public:
	GraphicalObject(float x, float y, ObjectType _ID, const sf::Texture* _texture);
};
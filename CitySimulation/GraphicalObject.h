#pragma once
#include <SFML/Graphics.hpp>

enum class ObjectType {UNIDENTIFIED, CAR, PRILIVEGEDCAR, CROSSING, ROAD, BUILDING};

class GraphicalObject :
	public sf::RectangleShape
{
public:
	GraphicalObject(float x, float y, float sizeX, float sizeY, ObjectType _ID, sf::Texture* _texture);
	~GraphicalObject();
	ObjectType getID();
private:
	ObjectType ID;
	sf::Texture* usedTexture;
};
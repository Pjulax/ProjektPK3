#include "Manager.h"

Manager::Manager()
{
}

Manager::Manager(int _xCrossAmount, int _yCrossAmount)
{
	this->xCrossAmount = _xCrossAmount;
	this->yCrossAmount = _yCrossAmount;
}

bool Manager::checkCollision()
{
	return false;
}

void Manager::generateMap()
{
    generateBuildings();
    generateRoads();
    generateCrossings();
    generateCars();
}

void Manager::generateBuildings()
{
    sf::Vector2f makePoint(0.0, 0.0);
    //buildings generation;

    for (int i = 0; i <= this->xCrossAmount; i++) 
    {
        for (int j = 0; j <= this->yCrossAmount; j++) 
        {
            sf::Texture* buildingTexture = new sf::Texture();
            buildingTexture->loadFromFile("Building.png", sf::IntRect(0, 0, 128, 128));
            Buildings.push_back(new Building(makePoint.x, makePoint.y, buildingTexture));
            makePoint.y = makePoint.y + 128.f + 64.f;
        }
        makePoint.y = 0.f;
        makePoint.x = makePoint.x + 128 + 64;
    }

}

void Manager::generateRoads()
{   //roads generation;

    //makes all roads from left to right
    sf::Vector2f makePoint(0.0, 128.0);

    for (int i = 0; i <= this->xCrossAmount; i++) 
    {
        for (int j = 0; j < this->yCrossAmount; j++) 
        {
            sf::Texture* roadTexture = new sf::Texture();
            roadTexture->loadFromFile("RoadShort.png", sf::IntRect(0, 0, 128, 64));
            Roads.push_back(new Road(makePoint.x, makePoint.y, roadTexture));
            makePoint.y = makePoint.y + 128.f + 64.f;
        }
        makePoint.y = 128.f;
        makePoint.x = makePoint.x + 128 + 64;
    }

    //makes all roads from up to down
    makePoint.y = 0.f;
    makePoint.x = 128.f + 64.f;


    for (int i = 0; i < this->xCrossAmount; i++)
    {
        for (int j = 0; j <= this->yCrossAmount; j++)
        {
            sf::Texture* roadTexture = new sf::Texture();
            roadTexture->loadFromFile("RoadShort.png", sf::IntRect(0, 0, 128, 64));
            Roads.push_back(new Road(makePoint.x, makePoint.y, roadTexture));
            Roads.back()->setRotation(90);
            makePoint.y = makePoint.y + 128.f + 64.f;
        }
        makePoint.y = 0.f;
        makePoint.x = makePoint.x + 128 + 64;
    }
}

void Manager::generateCrossings()
{
    sf::Vector2f makePoint(128.0, 128.0);
    //buildings generation;

    for (int i = 0; i < this->xCrossAmount; i++)
    {
        for (int j = 0; j < this->yCrossAmount; j++)
        {
            sf::Texture* crossingTexture = new sf::Texture();
            crossingTexture->loadFromFile("Crossing.png", sf::IntRect(0, 0, 128, 128));
            Crossings.push_back(new Crossing(makePoint.x, makePoint.y, crossingTexture));
            makePoint.y = makePoint.y + 128.f + 64.f;
        }
        makePoint.y = 128.f;
        makePoint.x = makePoint.x + 128 + 64;
    }


}

void Manager::generateCars()
{

}

int Manager::RunApplication()
{
	// Map & Window size initializing
    this->xCrossAmount = 5;
    this->yCrossAmount = 4;
    unsigned int windowXsize = this->xCrossAmount * (128 + 64) + 128,
                 windowYsize = this->yCrossAmount * (128 + 64) + 128;
    // Window initializing
    sf::RenderWindow window(sf::VideoMode(windowXsize, windowYsize), "City Simulation");

    generateMap();

    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;

        
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) {
                window.close();
                throw(1);
            }
            //OBS£UGA ESCAPE
        }

        // clear the window with white color
        window.clear(sf::Color::White);

        // draw everything here...
        for (ImmovableObject* building : Buildings) {
            window.draw(*building);
        }
        for (ImmovableObject* road : Roads) {
            window.draw(*road);
        }
        for (ImmovableObject* crossing : Crossings) {
            window.draw(*crossing);
        }
        // end the current frame
        window.display();
    }
    this->Buildings.clear();
	return 0;
}

bool Manager::moveCars()
{
    if (!Cars.empty()) {
        for (MovableObject* car : Cars) {
            car->moveObj();
            if (car->isMapEnd(800,600)) {
                delete car;
                car = nullptr;
            }
            if (car->onCrossing()) {
                car->directionGenerate();
            }
        }
        std::remove(Cars.begin(), Cars.end(), nullptr);
    }
    
	return false;
}

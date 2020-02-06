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

bool Manager::generateMap()
{
	sf::Vector2f makePoint(0.0, 0.0);
//buildings generate;
	
	for (int i = 0; i <= this->xCrossAmount; i++) {
		for (int j = 0; j <= this->yCrossAmount; j++) {
			sf::Texture buildingTexture;
			buildingTexture.loadFromFile("Building.png", sf::IntRect(0, 0, 128, 128));
			Buildings.push_back(new Building(makePoint.x, makePoint.y, sf::Texture()));
			Buildings.back()->getTexture(&buildingTexture)
			makePoint.y = makePoint.x + 128.f + 64.f;
		}
		makePoint.y = 0.f;
		makePoint.x = makePoint.x + 128 + 64;
	}
}

int Manager::RunApplication()
{
	// Window initializing
	sf::RenderWindow window(sf::VideoMode(800, 600), "City Simulation");

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

        // end the current frame
        window.display();
    }

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

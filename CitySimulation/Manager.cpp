#include "Manager.h"

bool Manager::checkCollision()
{
	return false;
}

Manager::Manager()
{
}

Manager::Manager(std::vector<GraphicalObject*> _Cars, std::vector<GraphicalObject*> _Roads, std::vector<GraphicalObject*> _Buildings, std::vector<GraphicalObject*> _Crossings)
{
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


        // end the current frame
        window.display();
    }

	return 0;
}

bool Manager::moveCars()
{
    if (!Cars.empty()) {
        for (MovableObject* car : Cars) {
            car->move();
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

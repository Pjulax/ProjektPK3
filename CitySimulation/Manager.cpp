#include "Manager.h"

Manager::Manager()
{
}

Manager::Manager(int _xCrossAmount, int _yCrossAmount)
{
	this->xCrossAmount = _xCrossAmount;
	this->yCrossAmount = _yCrossAmount;
}

void Manager::RunApplication()
{
    // FILE LOADING - if exists!

	// Map & Window size initializing
    this->xCrossAmount = 2;
    this->yCrossAmount = 2;
    unsigned int windowXsize = this->xCrossAmount * (128 + 64) + 128,
                 windowYsize = this->yCrossAmount * (128 + 64) + 128;
    // Window initializing
    sf::RenderWindow window(sf::VideoMode(windowXsize, windowYsize), "City Simulation");
    window.setFramerateLimit(60);

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

        // Cars movement logic function
        

        //TIME HANDLING

        //sf::Clock clock;
        //sf::Time time = clock.getElapsedTime();
        //if (time.asMilliseconds() > 200) {
        //    clock.restart();
        //}


        if (moveCars(windowXsize, windowYsize)) {

            // clear the window with white color
            window.clear(sf::Color::White);


            // Map Drawing
            for (ImmovableObject* building : Buildings) {
                window.draw(*building);
            }
            for (ImmovableObject* road : Roads) {
                window.draw(*road);
            }
            for (ImmovableObject* crossing : Crossings) {
                window.draw(*crossing);
            }
            // Cars drawing
            for (MovableObject* car : Cars) {
                window.draw(*car);

            }

            // end the current frame
            window.display();

        }
        // Memory freeing
        else { 
            for (int i = 0; i < Buildings.size(); i++) {
                delete Buildings[i];
            }
            for (int i = 0; i < Roads.size(); i++) {
                delete Roads[i];
            }
            for (int i = 0; i < Crossings.size(); i++) {
                delete Crossings[i];
            }
            for (int i = 0; i < Cars.size(); i++) {
                delete Cars[i];
            }
            // Clearing vectors -> deleting pointers to nowhere
            Buildings.clear();
            Roads.clear();
            Crossings.clear();
            Cars.clear();

            break;
        }
    }
}

bool Manager::moveCars(int winXsize, int winYsize)
{
    bool anyCarsOnMap = false;

    if (!Cars.empty()) {
        for (MovableObject* car : Cars) {
            if (!car->isMapEnd(winXsize, winYsize)) {
                
                anyCarsOnMap = true;

                if (car->onCrossing() && !car->isInCrossingQueue()) {
                    car->setInCrossingQueue(true);
                    car->directionGenerate;
                }




                car->moveObj();
            }
        }
    }
    
	return anyCarsOnMap;
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
    linkingRoads();
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
    sf::Vector2f makePoint(64.0, 160.0);

    for (int i = 0; i <= this->xCrossAmount; i++)
    {
        for (int j = 0; j < this->yCrossAmount; j++)
        {
            sf::Texture* roadTexture = new sf::Texture();
            roadTexture->loadFromFile("Road.png", sf::IntRect(0, 0, 128, 64));
            Roads.push_back(new Road(makePoint.x, makePoint.y, roadTexture));
            Roads.back()->setOrigin(64.0f, 32.0f);
            makePoint.y = makePoint.y + 128.f + 64.f;
        }
        makePoint.y = 160.f;
        makePoint.x = makePoint.x + 128 + 64;
    }

    //makes all roads from up to down
    makePoint.y = 64.f;
    makePoint.x = 160.f;


    for (int i = 0; i < this->xCrossAmount; i++)
    {
        for (int j = 0; j <= this->yCrossAmount; j++)
        {
            sf::Texture* roadTexture = new sf::Texture();
            roadTexture->loadFromFile("Road.png", sf::IntRect(0, 0, 128, 64));
            Roads.push_back(new Road(makePoint.x, makePoint.y, roadTexture));
            Roads.back()->setRotation(90);
            Roads.back()->setOrigin(64.0f, 32.0f);
            makePoint.y = makePoint.y + 128.f + 64.f;
        }
        makePoint.y = 64.f;
        makePoint.x = makePoint.x + 128 + 64;
    }
}

void Manager::generateCrossings()
{
    sf::Vector2f makePoint(160.0, 160.0);
    //buildings generation;

    for (int i = 0; i < this->xCrossAmount; i++)
    {
        for (int j = 0; j < this->yCrossAmount; j++)
        {
            sf::Texture* crossingTexture = new sf::Texture();
            crossingTexture->loadFromFile("Crossing.png", sf::IntRect(0, 0, 64, 64));
            Crossings.push_back(new Crossing(makePoint.x, makePoint.y, crossingTexture));
            Crossings.back()->setOrigin(32.0f, 32.0f);
            makePoint.y = makePoint.y + 128.f + 64.f;
        }
        makePoint.y = 160.f;
        makePoint.x = makePoint.x + 128 + 64;
    }


}

void Manager::generateCars() // File loaded cars handling remaining!
{
    if (fileLoaded) {

    }
    else {
        srand(time(0));
        sf::Vector2f makePoint(0.0, 0.0);
        //cars generation;
        for (ImmovableObject* road : Roads)
        {
            sf::Texture* carTexture = new sf::Texture();
            carTexture->loadFromFile("RedCar.png", sf::IntRect(0, 0, 32, 16));
            int oppositeDir = rand() % 2;

            if (road->getRotation() == 0 && oppositeDir == 0) { // rotation = 0
                makePoint.x = road->getPosition().x;
                makePoint.y = road->getPosition().y + 16;
            }
            else if (road->getRotation() == 0 && oppositeDir == 1) { // rotation = 180
                makePoint.x = road->getPosition().x;
                makePoint.y = road->getPosition().y - 16;
            }
            else if (road->getRotation() == 90 && oppositeDir == 0) { // rotation = 90
                makePoint.x = road->getPosition().x - 16;
                makePoint.y = road->getPosition().y;
            }
            else if (road->getRotation() == 90 && oppositeDir == 1) { // rotation = 270
                makePoint.x = road->getPosition().x + 16;
                makePoint.y = road->getPosition().y;
            }

            Cars.push_back(new Car(makePoint.x, makePoint.y, road, carTexture));
            Cars.back()->setRotation(road->getRotation() + (oppositeDir * 180));
            Cars.back()->setOrigin(16.0f, 8.0f);
        }
    }
}

void Manager::linkingRoads()
{
    sf::Vector2f roadCenter(0.0f,0.0f);

    for (ImmovableObject* road : Roads) {
        roadCenter.x = road->getPosition().x;
        roadCenter.y = road->getPosition().y;
        
        for (ImmovableObject* crossing : Crossings) {
            if (roadCenter.y == crossing->getPosition().y) {
                if (crossing->getPosition().x - roadCenter.x == 96) {
                    road->setNext(crossing);
                    crossing->setLeft(road);
                    std::cout << "Road saves right crossing" << std::endl;
                }
                else if (roadCenter.x - crossing->getPosition().x == 96) {
                    road->setPrev(crossing);
                    crossing->setRight(road);
                    std::cout << "Road saves left crossing" << std::endl;
                }
            }
            else if (roadCenter.x == crossing->getPosition().x) {
                if (crossing->getPosition().y - roadCenter.y == 96) {
                    road->setNext(crossing);
                    crossing->setUpper(road);
                    std::cout << "Road saves lower crossing" << std::endl;
                }
                else if (roadCenter.y - crossing->getPosition().y == 96) {
                    road->setPrev(crossing);
                    crossing->setLower(road);
                    std::cout << "Road saves upper crossing" << std::endl;
                }
            }
        }
    }
}

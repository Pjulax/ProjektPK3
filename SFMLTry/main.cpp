//#include <SFML/Graphics.hpp>
//#include "TestClass.h"
//
//int main()
//{
//	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
//	sf::CircleShape shape(100.f,3);
//	sf::RectangleShape rectan(sf::Vector2f(250,150));
//	shape.setFillColor(sf::Color::Green);
//	shape.setOutlineThickness(50.f);
//	shape.setOutlineColor(sf::Color(250, 150, 100));
//	rectan.setFillColor(sf::Color::Color(250,100,125));
//	sf::Clock clock;
//	sf::Time elapsed1;
//	bool SetFlag = true;
//
//	while (window.isOpen())
//	{	
//		if (SetFlag) {
//			shape.setPosition(150.f, 150.f);
//			SetFlag = false;
//		}
//		elapsed1 = clock.getElapsedTime();
//		if (elapsed1.asMilliseconds() > 20) {
//			clock.restart();
//			//shape.rotate(1.f);
//			//shape.move(5.f, 5.f);
//			rectan.move(1.f, 1.f);
//			rectan.setRotation(45.f);
//			
//		}
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				window.close();
//		}
//
//		window.clear();
//		window.draw(shape);
//		window.draw(rectan);
//		window.display();
//	}
//
//	return 0;
//}

#include <SFML/Graphics.hpp>    

int main()
{
	//Example for making a rectangle move around
	sf::RenderWindow screen(sf::VideoMode(800, 600), "Rectangle shape test"); //Create a window
	screen.setFramerateLimit(60); //Limit the frame rate to 60

	sf::RectangleShape rectangle(sf::Vector2f(40,50)); //Instantiate rectangle object
	rectangle.setFillColor(sf::Color::Blue); //Color the rectangle with blue
	rectangle.setPosition(400, 200); //Set the rectangle's position to 100, 100

	while (screen.isOpen()) //loop to update the window
	{
		sf::Event event; //Create an event class

		while (screen.pollEvent(event)) //Poll all possible events
		{
			if (event.type == sf::Event::Closed) //If the user hits the red X button
				screen.close(); //If true, close the window

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) //If the user is holding down the key "W"
				rectangle.move(0, 5); //move the rectangle 5 pixels on the y axis
		}

		screen.clear(); //Clear the screen of all elements

		screen.draw(rectangle); //Draw the rectangle

		screen.display(); //Display it
	}
}
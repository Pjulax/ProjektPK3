#include <SFML/Graphics.hpp>
#include "TestClass.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	sf::CircleShape shape(100.f,3);
	sf::RectangleShape rectan(sf::Vector2f(250,150));
	shape.setFillColor(sf::Color::Green);
	shape.setOutlineThickness(50.f);
	shape.setOutlineColor(sf::Color(250, 150, 100));
	rectan.setFillColor(sf::Color::Color(250,100,125));
	sf::Clock clock;
	sf::Time elapsed1;
	bool SetFlag = true;

	while (window.isOpen())
	{	
		if (SetFlag) {
			shape.setPosition(150.f, 150.f);
			SetFlag = false;
		}
		elapsed1 = clock.getElapsedTime();
		if (elapsed1.asMilliseconds() > 20) {
			clock.restart();
			//shape.rotate(1.f);
			//shape.move(5.f, 5.f);
			rectan.move(1.f, 1.f);
			rectan.setRotation(45.f);
			
		}
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.draw(rectan);
		window.display();
	}

	return 0;
}
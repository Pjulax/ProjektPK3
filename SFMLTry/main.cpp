#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 800), "SFML works!");
	sf::CircleShape shape(400.f,5);
	sf::RectangleShape rectan(sf::Vector2f(250,150));
	shape.setFillColor(sf::Color::Green);
	shape.setOutlineThickness(50.f);
	shape.setOutlineColor(sf::Color(250, 150, 100));
	rectan.setFillColor(sf::Color::Color(0,100,125,52));

	while (window.isOpen())
	{
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
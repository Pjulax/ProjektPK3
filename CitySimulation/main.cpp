//Manager - simulation organisator
#include "Manager.h"

int main() {
    Manager appManager = Manager();
    try {
        appManager.RunApplication();
    }
    catch (int exception) {
        if (exception == 1) {
            std::cout << "Window closed" << std::endl;
        }
    }

	return 0;
}




//// Texture loading for sprites
//sf::Texture texture1;
//if (!texture1.loadFromFile("RescueCarSmall.png", sf::IntRect(0, 0, 64, 128)))
//{
//    // error...
//    std::cout << "ERROR ON TEXTURE1" << std::endl;
//}
//sf::Texture texture2;
//if (!texture2.loadFromFile("RedCarSmall.png", sf::IntRect(0, 0, 64, 128)))
//{
//    // error...
//    std::cout << "ERROR ON TEXTURE2" << std::endl;
//}

//// Sprites loading
//sf::Sprite sprite1;
//sprite1.setTexture(texture1);
//sf::Sprite sprite2;
//sprite2.setTexture(texture2);
//sprite1.setPosition(32.f, 64.f);
//sprite2.setPosition(32.f, 64.f);
//sprite1.setOrigin(sf::Vector2f(32.f, 64.f));
//sprite2.setOrigin(sf::Vector2f(32.f, 64.f));


//// Clock and time measurer initializing
//sf::Clock clock, clock2;
//clock.restart();
//sf::Time time, time2;


// run the program as long as the window is open
//while (window.isOpen())
//{
//    // check all the window's events that were triggered since the last iteration of the loop
//    sf::Event event;

//    // moving by 1 pixel every 16 milliseconds ( its a little more than 60 times per second (60 Hz) 16,66 millisec for 60 Hz)
//    time = clock.getElapsedTime();
//    if (time.asMilliseconds() > 16) {
//        
//        sprite1.move(sf::Vector2f(1.f, 0));
//        sprite2.move(sf::Vector2f(0, 1.f));
//        clock.restart();
//    }

//    // Rotating every one second
//    time2 = clock2.getElapsedTime();
//    if (time2.asSeconds() > 1) {
//        sprite1.rotate(90.0);
//        sprite2.rotate(180.0);
//        clock2.restart();
//    }


//    while (window.pollEvent(event))
//    {
//        // "close requested" event: we close the window
//        if (event.type == sf::Event::Closed)
//            window.close();
//    }

//    // clear the window with black color
//    window.clear(sf::Color::White);

//    // draw everything here...
//    // window.draw(...);

//    window.draw(sprite1);
//    window.draw(sprite2);

//    // end the current frame
//    window.display();
//}
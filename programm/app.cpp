#include "app.hpp"

App::App()
{
    window.create(sf::VideoMode(900, 900), "triangle");
}

void
App::run()
{
    sf::Event event;

    while (window.isOpen())
    {

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {

                window.close();
            }
        }
        window.clear();

        triangle.draw(window);

        triangle.addPoint();

        window.display();
    }
}
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

            sf::Vector2f cursor_position =
                sf::Vector2f(sf::Mouse::getPosition(window).x,
                             sf::Mouse::getPosition(window).y);

            triangle.changeVertexPosition(
                cursor_position, sf::Mouse::isButtonPressed(sf::Mouse::Left));
        }

        window.clear();

        triangle.draw(window);

        triangle.addPoint();

        window.display();
    }
}
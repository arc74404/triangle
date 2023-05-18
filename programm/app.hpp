#ifndef APP_HPP
#define APP_HPP

#include "random"

#include "triangle.hpp"

class App
{
public:
    void run();

    App();

private:
    sf::RenderWindow window;

    Triangle triangle;
};

#endif // APP_HPP
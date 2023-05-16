#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <SFML/Graphics.hpp>

#include <iostream>

class Triangle
{
public:
    Triangle();

    void draw(sf::RenderWindow& w);

    void addPoint();

private:
    sf::VertexArray vertexes;

    sf::VertexArray points;

    int count_points;

    sf::Vector2f last_point;
};

#endif // TRIANGLE_HPP
#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <SFML/Graphics.hpp>

#include <algorithm>
#include <cmath>
#include <iostream>

class Triangle
{
public:
    Triangle();

    void draw(sf::RenderWindow& w);

    void addPoint();

    void changeVertexPosition(sf::Vector2f cursor_position, bool mouse_pressed);

private:
    enum class Type
    {
        DEFAULT = 0,
        CHANGING = 1
    };

    int index_choosing_point;

    Type type;

    sf::VertexArray extra_triangle;

    sf::VertexArray vertexes;

    sf::VertexArray points;

    int count_points;

    const int max_count_points = 15000;

    sf::Vector2f last_point;
};

#endif // TRIANGLE_HPP
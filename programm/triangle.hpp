#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <algorithm>
#include <cmath>
#include <iostream>

#include "myvertex.hpp"

class Triangle
{
public:
    Triangle();

    void draw(sf::RenderWindow& w);

    void addPoint();

    void changeVertexPosition(sf::Vector2f cursor_position, bool mouse_pressed);

    void setExtraTriangleColor(sf::Color color);

    void setColor(sf::Color color);

private:

    enum class Type
    {
        DEFAULT = 0,
        CHANGING = 1
    };

    int index_choosing_point;

    Type type;

    sf::VertexArray extra_triangle;

    std::vector<MyVertex> vertexes;

    sf::VertexArray points;

    const int max_count_points = 15000;

    sf::Vertex last_point;

};

#endif // TRIANGLE_HPP
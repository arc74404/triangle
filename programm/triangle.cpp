#include "triangle.hpp"

Triangle::Triangle()
{
    vertexes.setPrimitiveType(sf::PrimitiveType::LineStrip);
    vertexes.resize(4);

    vertexes[0].position = sf::Vector2f(100, 100);
    vertexes[1].position = sf::Vector2f(850, 368);
    vertexes[2].position = sf::Vector2f(456, 867);

    vertexes[3] = vertexes[0];

    last_point = sf::Vector2f(rand() % 900, rand() % 900);

    count_points = 1;
}

void
Triangle::draw(sf::RenderWindow& w)
{
    w.draw(vertexes);
    w.draw(points);
}

void
Triangle::addPoint()
{
    if (count_points == 12000) return;

    sf::Vector2f vertex = vertexes[rand() % 3].position;

    sf::Vector2f new_point = (vertex + last_point);

    new_point.x /= 2;
    new_point.y /= 2;

    points.append(sf::Vertex(new_point));

    last_point = new_point;

    ++count_points;
}
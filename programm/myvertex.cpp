#include "myvertex.hpp"

MyVertex::MyVertex(sf::Vector2f position, float rr)
    : sf::Vertex(position), radius(rr)
{
    circle.setPosition(position - sf::Vector2f(rr, rr));
    circle.setFillColor(sf::Color(212, 224, 76, 60));
    circle.setRadius(rr);
}

MyVertex::MyVertex() : sf::Vertex(), radius(20)
{
    circle.setPosition(sf::Vector2f(20, 20));
    circle.setFillColor(sf::Color(212, 224, 76, 60));
    circle.setRadius(20);
}

void
MyVertex::setPosition(sf::Vector2f pp)
{
    position = pp;
    circle.setPosition(position - sf::Vector2f(radius, radius));
}

sf::Vector2f
MyVertex::getPosition()
{
    return position;
}

float
MyVertex::getRadius()
{
    return radius;
}

void
MyVertex::draw(sf::RenderWindow& w)
{
    sf::VertexArray array;
    sf::Vertex point(position);
    point.color = color;
    array.append(point);
    w.draw(array);
    w.draw(circle);
}

void
MyVertex::setColor(sf::Color cc)
{
    color = cc;
}

sf::Color
MyVertex::getColor()
{
    return color;
}

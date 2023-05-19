#include "triangle.hpp"

Triangle::Triangle() : vertexes(3)
{

    vertexes[0].setPosition(sf::Vector2f(100, 100));
    vertexes[1].setPosition(sf::Vector2f(850, 368));
    vertexes[2].setPosition(sf::Vector2f(450, 860));

    extra_triangle.resize(4);

    for (int i = 0; i < 3; ++i)
    {
        extra_triangle[i].position = vertexes[i].getPosition();
    }

    extra_triangle[3] = extra_triangle[0];

    extra_triangle.setPrimitiveType(sf::PrimitiveType::LineStrip);

    setExtraTriangleColor(sf::Color::Green);

    last_point = sf::Vector2f(rand() % 900, rand() % 900);

    type = Type::DEFAULT;
}

void
Triangle::draw(sf::RenderWindow& w)
{
    for (int i = 0; i < 3 && type != Type::CHANGING; ++i)
    {
        vertexes[i].draw(w);
    }
    w.draw(points);
    if (type == Type::CHANGING)
    {
        w.draw(extra_triangle);
    }
}

void
Triangle::setExtraTriangleColor(sf::Color color)
{
    for (int i = 0; i < 4; ++i)
    {
        extra_triangle[i].color = sf::Color(color);
    }
}

void
Triangle::setColor(sf::Color color)
{
    for (int i = 0; i < 3; ++i)
    {
        vertexes[i].setColor(color);
    }
    for (int i = 0; i < points.getVertexCount(); ++i)
    {
        points[i].color = color;
    }
    last_point.color = color;
}

void
Triangle::changeVertexPosition(sf::Vector2f cursor_position, bool mouse_pressed)
{

    if (mouse_pressed && type == Type::DEFAULT)
    {
        float R = vertexes[0].getRadius();

        for (int i = 0; i < 3; ++i)
        {
            sf::Vector2f point = vertexes[i].getPosition();

            if (std::pow(cursor_position.x - point.x, 2) +
                    std::pow(cursor_position.y - point.y, 2) <=
                std::pow(R, 2))
            {
                type = Type::CHANGING;

                index_choosing_point = i;

                extra_triangle[i].position = cursor_position;

                if (i == 0) extra_triangle[3].position = cursor_position;
            }
        }
    }
    else if (type == Type::CHANGING)
    {
        if (mouse_pressed)
        {
            extra_triangle[index_choosing_point].position = cursor_position;
        }
        else
        {
            vertexes[index_choosing_point].setPosition(
                extra_triangle[index_choosing_point].position);

            type = Type::DEFAULT;
            points.clear();

            setColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
        }
        if (index_choosing_point == 0)
            extra_triangle[3].position = extra_triangle[0].position;
    }
}

void
Triangle::addPoint()
{
    if (points.getVertexCount() == max_count_points) return;

    sf::Vertex vertex = vertexes[rand() % 3].getPosition();

    sf::Vertex new_point;
    new_point.position = (vertex.position + last_point.position);

    new_point.position.x /= 2;
    new_point.position.y /= 2;

    new_point.color = last_point.color;

    points.append(sf::Vertex(new_point));

    last_point = new_point;
}
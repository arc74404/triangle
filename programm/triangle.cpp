#include "triangle.hpp"

Triangle::Triangle()
{
    vertexes.resize(4);

    vertexes[0].position = sf::Vector2f(100, 100);
    vertexes[1].position = sf::Vector2f(850, 368);
    vertexes[2].position = sf::Vector2f(456, 867);

    vertexes[3] = vertexes[0];

    extra_triangle = vertexes;
    extra_triangle.setPrimitiveType(sf::PrimitiveType::LineStrip);

    for (int i = 0; i < 4; ++i)
    {
        extra_triangle[i].color   = sf::Color::Green;
        extra_triangle[i].color.a = 0;
    }

    last_point = sf::Vector2f(rand() % 900, rand() % 900);

    count_points = 1;

    type = Type::DEFAULT;
}

void
Triangle::draw(sf::RenderWindow& w)
{
    w.draw(vertexes);
    w.draw(points);
    w.draw(extra_triangle);
}

void
Triangle::changeVertexPosition(sf::Vector2f cursor_position, bool mouse_pressed)
{

    if (mouse_pressed && type == Type::DEFAULT)
    {
        for (int i = 0; i < 3; ++i)
        {
            sf::Vector2f point = vertexes[i].position;

            float R = 50;

            if (std::pow(cursor_position.x - point.x, 2) +
                    std::pow(cursor_position.y - point.y, 2) <=
                std::pow(R, 2))
            {
                type = Type::CHANGING;

                index_choosing_point = i;

                extra_triangle[i].position = cursor_position;

                if (i == 0) extra_triangle[3].position = cursor_position;

                for (int j = 0; j < 4; ++j)
                {
                    extra_triangle[j].color.a = 255;
                }
                return;
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
            vertexes[index_choosing_point].position =
                extra_triangle[index_choosing_point].position;

            type = Type::DEFAULT;
            points.clear();

            count_points = 0;

            for (int j = 0; j < 4; ++j)
            {
                extra_triangle[j].color.a = 0;
            }
        }
        if (index_choosing_point == 0)
            extra_triangle[3].position = extra_triangle[0].position;
    }
}

void
Triangle::addPoint()
{
    if (count_points == max_count_points) return;

    sf::Vector2f vertex = vertexes[rand() % 3].position;

    sf::Vector2f new_point = (vertex + last_point);

    new_point.x /= 2;
    new_point.y /= 2;

    points.append(sf::Vertex(new_point));

    last_point = new_point;

    ++count_points;
}
#ifndef MY_VERTEX_HPP
#define MY_VERTEX_HPP

#include <SFML/Graphics.hpp>

class MyVertex : protected sf::Vertex
{
public:
    MyVertex(sf::Vector2f position, float radius);

    MyVertex();

    void setPosition(sf::Vector2f pp);

	sf::Vector2f getPosition();

    void setColor(sf::Color cc);

	sf::Color getColor();

    float getRadius();

    void draw(sf::RenderWindow& w);

private:
    sf::CircleShape circle;

    float radius;
};

#endif // MY_VERTEX_HPP
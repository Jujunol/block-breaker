#include "Main.hpp"

#define WIDTH 30
#define HEIGHT 15

Block::Block(float x, float y)
	: RectangleShape(sf::Vector2f(WIDTH, HEIGHT)) {
	setFillColor(sf::Color(221, 221, 221, 255));
	setPosition(x, y);
}


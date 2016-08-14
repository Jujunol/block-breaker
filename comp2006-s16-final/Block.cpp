#include "Main.hpp"

#define WIDTH 30
#define HEIGHT 15

sf::Texture Block::texture;

Block::Block(float x, float y)
	: RectangleShape(sf::Vector2f(WIDTH, HEIGHT)) {

	setTexture(&texture);
	setFillColor(sf::Color(221, 221, 221, 255));
	setPosition(x, y);
}


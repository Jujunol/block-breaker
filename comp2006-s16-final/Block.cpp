#include "Main.hpp"

const int WIDTH = 30, HEIGHT = 15;

sf::Texture Block::texture;

Block::Block(float x, float y)
	: RectangleShape(sf::Vector2f(WIDTH, HEIGHT)) {

	setTexture(&texture);
	setFillColor(sf::Color(221, 221, 221, 255));
	setPosition(x, y);
}


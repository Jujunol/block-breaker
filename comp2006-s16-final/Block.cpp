#include "Main.hpp"

#define WIDTH 75
#define HEIGHT 25

std::vector<Block*> blockList;

Block::Block(float x, float y)
	: RectangleShape(sf::Vector2f(WIDTH, HEIGHT)) {
	blockList.push_back(this);
	setFillColor(sf::Color(221, 221, 221, 255));
	setPosition(x, y);
}

std::vector<Block *>& Block::getBlockList() {
	return blockList;
}
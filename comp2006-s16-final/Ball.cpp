#include "Main.hpp"

#define RADIUS 10
#define EDGES 50U

Ball::Ball() : CircleShape(RADIUS)  {}

Ball::Ball(Game* game)
	: CircleShape(RADIUS, EDGES) {
	this->game = game;
	this->windowSize = game->getWindow()->getSize();

	setFillColor(sf::Color::White);
	// position to the center of the window
	setPosition(windowSize.x / 2 - RADIUS, windowSize.y / 2 - RADIUS);
	moveDir = sf::Vector2f(0, getSpeed());
}

void Ball::update(float delta) {
	move(moveDir.x * delta, moveDir.y * delta);
	game->outOfBounds(this);
}

void Ball::setMoveDir(sf::Vector2f& moveDir) {
	this->moveDir = moveDir;
}

sf::Vector2f& Ball::getMoveDir() {
	return moveDir;
}

float Ball::getSpeed() {
	return 0.5f;
}

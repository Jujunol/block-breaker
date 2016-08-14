#include "Main.hpp"

const int RADIUS = 10, EDGES = 50U;
const float PI_F = 3.14159265358979f;

Ball::Ball() : CircleShape(RADIUS)  {}

Ball::Ball(Game* game)
	: CircleShape(RADIUS, EDGES) {
	this->game = game;
	this->windowSize = game->getWindow()->getSize();

	if (!texture.loadFromFile("ball-texture.png")) {
		std::cout << "file not found!" << std::endl;
	}

	setTexture(&texture);
	setFillColor(sf::Color::White);
	// position to the center of the window
	setPosition(windowSize.x / 2 - RADIUS, windowSize.y / 2 - RADIUS);
	moveDir = sf::Vector2f(0, getSpeed());
}

void Ball::update(float delta) {
	move(moveDir.x * delta, moveDir.y * delta);
	game->outOfBounds(this);
}

void Ball::bounceOff(sf::Shape& shape) {
	float shapeWidth = shape.getGlobalBounds().width;

	// calculate the center of the ball, highest diameter
	float ballCenter = getPosition().x + getGlobalBounds().width / 2;

	// find the point of intersection relative to the paddle
	float poi = ballCenter - shape.getPosition().x;

	// find min and max factors
	float minFactor = shapeWidth * 0.1;
	float maxFactor = shapeWidth - minFactor;

	// error prevention for different collisions
	if (poi < minFactor) poi = minFactor;
	else if (poi > maxFactor) poi = maxFactor;

	// find the angle to launch the ball in Radians
	float angle = PI_F * (shapeWidth - poi) / shapeWidth;

	// find the x and y movement factors
	float x = cosf(angle) * getSpeed();
	float y = sinf(angle) * getSpeed() * -(moveDir.y / abs(moveDir.y));

	// print it out for debugging
	std::cout << "Ball Center: " << ballCenter << std::endl
		<< "POI: " << poi << std::endl
		<< "Angle: " << angle << std::endl
		<< "Move X: " << x << std::endl
		<< "Move Y: " << y << std::endl << std::endl;

	// set the movement vector
	moveDir.x = x;
	moveDir.y = y;
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

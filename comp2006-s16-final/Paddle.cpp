#include "Main.hpp"

static const int WIDTH = 100, HEIGHT = 10;

Paddle::Paddle() : RectangleShape(sf::Vector2f(WIDTH, HEIGHT)) {}

Paddle::Paddle(Game* game) 
	: RectangleShape(sf::Vector2f(WIDTH, HEIGHT)) {
	this->game = game;
	this->windowSize = game->getWindow()->getSize();

	/*if (!texture.loadFromFile("paddle-texture.png")) {
		std::cout << "Couldn't load paddle texture" << std::endl;
	}*/

	// position in center of window on x axis
	setPosition((windowSize.x / 2 - WIDTH / 2), (windowSize.y - 20));
	//setTexture(&texture);
}

void Paddle::update(float delta) {
	float speed = 0.5f * delta;

	// moving left or right ?
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		move(-speed, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		move(speed, 0);
	}

	game->outOfBounds(this);
}

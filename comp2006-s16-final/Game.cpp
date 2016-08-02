#include "Main.hpp"

static const int BLOCK_WIDTH = 30, BLOCK_HEIGHT = 15;

Game::Game(sf::RenderWindow& window) {
	this->window = &window;
	paddle = Paddle(this);
	ball = Ball(this);

	for (int i = 0; i < 50; i++) {
		Block block((i % 10) * (BLOCK_WIDTH * 2) + 15, (i % 3) * (BLOCK_HEIGHT * 2.5) + 25);
		blockList.push_back(block);
	}
}

void Game::update(float delta) {
	paddle.update(delta);
	ball.update(delta);

	// check if game over (ie. ball is below the paddle)
	if (window->getSize().y - (ball.getPosition().y + ball.getLocalBounds().height) <= 10) {
		std::cout << "Game over!" << std::endl;
		//window->close();
	}

	if (ball.getGlobalBounds().intersects(paddle.getGlobalBounds())) {
		ball.bounceOff(paddle);
	}
	else if (ball.getPosition().y <= 0) {
		sf::Vector2f moveDir = ball.getMoveDir();
		moveDir.y *= -1;
		ball.setMoveDir(moveDir);
	}
	else if (ball.getPosition().x <= 0 || ball.getPosition().x + ball.getGlobalBounds().width >= window->getSize().x) {
		sf::Vector2f moveDir = ball.getMoveDir();
		moveDir.x *= -1;
		ball.setMoveDir(moveDir);
	}

	for (Block& block : blockList) {
		if (block.visible && ball.getGlobalBounds().intersects(block.getGlobalBounds())) {
			block.visible = false;
			ball.bounceOff(block);
		}
	}
}

void Game::drawObjects() {
	// draw shapes
	window->draw(paddle);
	window->draw(ball);

	//std::cout << std::string(10, '-') << std::endl;
	for (Block block : blockList) {
		//std::cout << block.getPosition().x << " - " << block.getPosition().y << std::endl;
		if (block.visible) 
			window->draw(block);
	}
	//std::cout << std::string(10, '-') << std::endl;
}

void Game::outOfBounds(sf::Shape* shape) {
	float xPos = shape->getPosition().x;
	float yPos = shape->getPosition().y;
	float width = shape->getGlobalBounds().width;
	float height = shape->getGlobalBounds().height;

	// check the x-axis
	if (xPos < 0) {
		shape->move(-xPos, 0);
	}
	else if (xPos + width > window->getSize().x) {
		shape->move(-(xPos + width - window->getSize().x), 0);
	}

	// check the y-axis
	if (yPos < 0) {
		shape->move(0, -yPos);
	}
	else if (yPos + height > window->getSize().y) {
		shape->move(0, -(yPos + height - window->getSize().y));
	}
}

sf::RenderWindow* Game::getWindow() {
	return window;
}
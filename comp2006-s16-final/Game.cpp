#include "Main.hpp"

const float  PI_F = 3.14159265358979f;

Game::Game(sf::RenderWindow& window) {
	//makeBall();
	this->window = &window;
	paddle = Paddle(this);
	ball = Ball(this);

	
	/*Block oneBlock(10, 10);
	Block secBlock(10, 25);*/
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
		// calculate the center of the ball, highest diameter
		float ballCenter = ball.getPosition().x + ball.getGlobalBounds().width / 2;

		// find the point of intersection relative to the paddle
		float poi = ballCenter - paddle.getPosition().x;

		// error prevention for different collisions
		if (poi < 0) poi = 0;
		else if (poi > paddle.getGlobalBounds().width) poi = paddle.getGlobalBounds().width;

		// find the angle to launch the ball in Radians
		float angle = PI_F * (paddle.getGlobalBounds().width - poi) / paddle.getGlobalBounds().width;

		// find the x and y movement factors
		float x = cosf(angle) * ball.getSpeed();
		float y = sinf(angle) * ball.getSpeed() * -1;

		// print it out for debugging
		std::cout << "Ball Center: " << ballCenter << std::endl
			<< "POI: " << poi << std::endl
			<< "Angle: " << angle << std::endl
			<< "Move X: " << x << std::endl
			<< "Move Y: " << y << std::endl << std::endl;

		// set the movement vector
		ball.setMoveDir(sf::Vector2f(x, y));
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
}
void Game::makeBall() {

	Block thridBlock(50, 50);
	Block thridBlock1(100, 50);
	Block thridBlock2(150, 50);

}
void Game::drawObjects() {
	// draw shapes
	window->draw(paddle);
	window->draw(ball);

	/*std::vector<Block *> ptr;
	ptr.push_back(&thridBlock);
	ptr.push_back(&thridBlock1);
	ptr.push_back(&thridBlock2);*/
	
	Block oneBlock(50.0f, 50.0f);
	//window->draw(oneBlock);

	//std::cout << std::string(10, '-') << std::endl;
	for (Block* block : Block::getBlockList()) {
		std::cout << block->getPosition().x << " - " << block->getPosition().y << std::endl;
		window->draw(*block);
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
#include "Main.hpp"

//class MyPaddle : public sf::RectangleShape {
//private:
//	sf::Texture texture;
//public:
//	MyPaddle(sf::Vector2u& windowSize) : RectangleShape(sf::Vector2f(100, 10)) {
//		if (!texture.loadFromFile("paddle-texture.png")) {
//			std::cout << "Couldn't load paddle texture" << std::endl;
//		}
//
//		setTexture(&texture);
//		setPosition((windowSize.x / 2 - 100 / 2), (windowSize.y - 20));
//	}
//};

int main() {
	sf::RenderWindow window(sf::VideoMode(600, 600), "My Project with SFML");
	sf::Clock clock;
	Game game(window);

	//MyPaddle myPaddle(window.getSize());

	sf::Font arial;
	arial.loadFromFile("arial.ttf");

	sf::Text frameDisplay("Frame Rate: ", arial, 16);
	frameDisplay.setColor(sf::Color::Red);

	window.setFramerateLimit(64);

	while (window.isOpen()) {
		sf::Event event;

		// check if close button or esc key is pressed
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
					window.close();
				break;
			}
		}

		// find change in time 
		float delta = clock.getElapsedTime().asMilliseconds();
		int fps = (1 / delta * 1000);

		frameDisplay.setString("Frame Rate: " + std::to_string(fps));
		game.update(delta);
		clock.restart();

		// render everything onto the screen
		window.clear();
		window.draw(frameDisplay);
		game.drawObjects();
		//window.draw(myPaddle);
		window.display();
	}

	return 0;
}
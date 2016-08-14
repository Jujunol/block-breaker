#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>

// class prototypes
class Game;

class Paddle : public sf::RectangleShape {
private:
	Game* game;
	sf::Texture texture;
	sf::Vector2u windowSize;
public:
	Paddle();
	Paddle(Game*);
	void update(float);
};

class Ball : public sf::CircleShape {
private:
	Game* game;
	sf::Texture texture;
	sf::Vector2u windowSize;
	sf::Vector2f moveDir;
public:
	Ball();
	Ball(Game*);
	void update(float);
	void bounceOff(sf::Shape&);
	void setMoveDir(sf::Vector2f&);
	sf::Vector2f& getMoveDir();
	float getSpeed();
};

class Block : public sf::RectangleShape {
public:
	bool visible = true;

	Block(float x, float y);
};

class Game {
private:
	sf::RenderWindow* window;
	std::vector<Block> blockList;
	Paddle* paddle;
	Ball* ball;
public:
	Game(sf::RenderWindow&);
	void update(float);
	void drawObjects();
	void outOfBounds(sf::Shape*);
	sf::RenderWindow* getWindow();
};

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
	sf::Vector2u windowSize;
public:
	Paddle();
	Paddle(Game*);
	void update(float);
};

class Ball : public sf::CircleShape {
private:
	Game* game;
	sf::Vector2u windowSize;
	sf::Vector2f moveDir;
public:
	Ball();
	Ball(Game*);
	void update(float);
	void setMoveDir(sf::Vector2f&);
	sf::Vector2f& getMoveDir();
	float getSpeed();
};

class Block : public sf::RectangleShape {
private:
	
public:
	Block(float x, float y);
	static std::vector<Block *>& getBlockList();
};

class Game {
private:
	sf::RenderWindow* window;
	Paddle paddle;
	Ball ball;
public:
	Game(sf::RenderWindow&);
	void update(float);
	void drawObjects();
	void outOfBounds(sf::Shape*);
	sf::RenderWindow* getWindow();
};

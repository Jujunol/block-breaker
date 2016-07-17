#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>

//class IGameObject {
//public:
//	virtual ~IGameObject() {}
//	virtual void update(float) = 0;
//	virtual void draw(sf::RenderWindow& window) {}
//};

// class prototypes
class Game;

class Paddle : public sf::RectangleShape/*, public IGameObject*/ {
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

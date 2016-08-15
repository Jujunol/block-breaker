#pragma once
#include <SFML/Graphics.hpp>

class Button {
private:
	static sf::Font font;

	int id;
	sf::CircleShape circle;
	sf::Text text;
public:
	Button();
	~Button();
	void draw(sf::RenderWindow* window);
	void setId(int id) { this->id = id; }

	static sf::Font& getFont() { return font; }
};

class Menu {
private:
	sf::RenderWindow* window;
	//Button buttons[5];
public:
	Menu(sf::RenderWindow&);
	~Menu();
	void update(float);
	void drawObjects();
};

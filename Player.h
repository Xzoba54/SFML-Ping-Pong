#pragma once

#include <SFML/Graphics.hpp>

class Player{
private:

	sf::RectangleShape* shape;

	float movementSpeed;

	void initShape();

public:

	Player();
	virtual ~Player();

	void move(float dirX, float dirY);
	sf::FloatRect getBounds();

	void update();
	void render(sf::RenderTarget& target);
};


#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"

class Ball{
private:

	sf::CircleShape* shape;

	float velocityX;
	float velocityY;
	float velocityMax;

	float points;

	void initCircle();

public:
	
	Ball();
	virtual ~Ball();

	void checkCollision(Player* player);

	void update();
	void render(sf::RenderTarget& target);
};


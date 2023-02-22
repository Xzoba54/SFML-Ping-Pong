#pragma once

#include <SFML/Graphics.hpp>

#include "Player.h"
#include "Ball.h"

class Game{	
private:

	sf::RenderWindow* window;

	Player* player;
	Ball* ball;

	void initWindow();
	void initPlayer();
	void initBall();

public:

	Game();
	virtual ~Game();

	void checkCollision();

	void udpatePollEvents();
	void updateInputs();
	void update();
	void render();
	void run();
};


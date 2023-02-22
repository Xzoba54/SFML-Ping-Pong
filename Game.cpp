#include "Game.h"

void Game::initWindow(){
	this->window = new sf::RenderWindow(sf::VideoMode(1000, 600), "Ping Pong", sf::Style::Default);
	this->window->setVerticalSyncEnabled(false);
	this->window->setFramerateLimit(165);
}

void Game::initPlayer(){
	this->player = new Player();
}

void Game::initBall(){
	this->ball = new Ball();
}

Game::Game(){
	this->initWindow();
	this->initPlayer();
	this->initBall();
}

Game::~Game(){
	delete this->window;
	delete this->player;
	delete this->ball;
}

void Game::checkCollision(){
	this->ball->checkCollision(this->player);
}

void Game::udpatePollEvents(){
	sf::Event ev;

	while (this->window->pollEvent(ev)) {
		if (ev.type == sf::Event::Closed) this->window->close();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) this->window->close();
	}
}

void Game::updateInputs(){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) this->player->move(-1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) this->player->move(1.f, 0.f);
}

void Game::update(){
	this->udpatePollEvents();
	this->updateInputs();

	this->checkCollision();

	this->player->update();
	this->ball->update();
}

void Game::render(){
	this->window->clear();

	this->player->render(*this->window);
	this->ball->render(*this->window);

	this->window->display();
}

void Game::run(){
	while (this->window->isOpen()) {
		this->update();
		this->render();
	}
}


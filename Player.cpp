#include "Player.h"

#include <SFML/Graphics.hpp>

void Player::initShape(){
	this->shape = new sf::RectangleShape();
	this->shape->setPosition(sf::Vector2f(350, 500));
	this->shape->setSize(sf::Vector2f(125, 20));
	this->shape->setFillColor(sf::Color::Blue);
}

Player::Player(){
	this->movementSpeed = 2;

	this->initShape();
}

Player::~Player(){
	delete this->shape;
}

void Player::move(float dirX, float dirY){
	this->shape->move(dirX * this->movementSpeed, dirY * this->movementSpeed);
}

sf::FloatRect Player::getBounds()
{
	return this->shape->getGlobalBounds();
}

void Player::update(){
	if (this->shape->getPosition().x <= 0) this->shape->setPosition(0.f, this->shape->getPosition().y);
	if (this->shape->getPosition().x + this->shape->getSize().x >= 1000) this->shape->setPosition(1000.f - this->shape->getSize().x, this->shape->getPosition().y);
}

void Player::render(sf::RenderTarget& target) {
	target.draw(*this->shape);
}
#include "Ball.h"

void Ball::initCircle(){
	this->shape = new sf::CircleShape();
	this->shape->setRadius(20);
	this->shape->setPointCount(20);
	this->shape->setPosition(sf::Vector2f(300, 200));
	this->shape->setFillColor(sf::Color::Red);
}

Ball::Ball(){
	this->points = 0;
	this->velocityMax = 1.5;
	this->velocityX = this->velocityMax;
	this->velocityY = this->velocityMax;

	this->initCircle();
}

Ball::~Ball(){
	delete this->shape;
}

void Ball::checkCollision(Player* player){
	if (this->shape->getGlobalBounds().top + this->shape->getGlobalBounds().height >= player->getBounds().top && this->shape->getGlobalBounds().left + this->shape->getGlobalBounds().width >= player->getBounds().left && this->shape->getGlobalBounds().left <= player->getBounds().left + player->getBounds().width){
		this->velocityY += 0.5f;
		this->velocityY *= -1;
		this->points++;
	}
}

void Ball::update(){
	if (this->shape->getPosition().y <= 0 || this->shape->getPosition().y + this->shape->getRadius() * 2 >= 600) this->velocityY *= -1;
	if (this->shape->getPosition().x <= 0 || this->shape->getPosition().x + this->shape->getRadius() * 2 >= 1000) this->velocityX *= -1;

	this->shape->move(this->velocityX, this->velocityY);
}

void Ball::render(sf::RenderTarget& target){
	target.draw(*this->shape);
}

#include "ball.h"
#include "program.h"
#include <cmath>

using namespace sf;
using namespace std;

Ball::Ball() {
	setRadious(defaultRadious);
	shape.setFillColor(Color::Cyan);
	position.x = defaultBeginningPositionX;
	position.y = defaultBeginningPositionY;
	shape.setPosition(position);
	speed.x = defaultBeginningSpeedX;
	speed.y = defaultBeginningSpeedY;
	isCollisionLeft = false;
	isCollisionRight = false;
	isCollisionTop = false;
	isCollisionBottom = false;
}

void Ball::update() {
	move();
	executeCollsion();
}

void Ball::move() {
	position.x += speed.x * Program::getDeltaTime();
	position.y += speed.y * Program::getDeltaTime();
	shape.setPosition(position);
}

void Ball::executeCollsion() {
	if(isCollisionLeft)
		speed.x = abs(speed.x);
	if(isCollisionRight)
		speed.x = -abs(speed.x);
	if(isCollisionTop)
		speed.y = abs(speed.y);
	if(isCollisionBottom)
		speed.y = -abs(speed.y);

	setCollisionLeft(false);
	setCollisionRight(false);
	setCollisionTop(false);
	setCollisionBottom(false);
}

void Ball::setCollisionLeft(bool value) {
	isCollisionLeft = value;
}

void Ball::setCollisionRight(bool value) {
	isCollisionRight = value;
}

void Ball::setCollisionTop(bool value) {
	isCollisionTop = value;
}

void Ball::setCollisionBottom(bool value) {
	isCollisionBottom = value;
}

void Ball::setRadious(float radious) {
	this->radious = radious;
	shape.setRadius(radious);
}

void Ball::setPosition(Vector2f position) {
	this->position = position;
	shape.setPosition(position);
}

void Ball::setSpeed(Vector2f speed) {
	this->speed = speed;
}

float Ball::getLeft() {
	return position.x;
}

float Ball::getRight() {
	return position.x + 2 * defaultRadious;
}

float Ball::getTop() {
	return position.y;
}

float Ball::getBottom() {
	return position.y + 2 * defaultRadious;
}

Vector2f Ball::getCenter() {
	return Vector2f{position.x + defaultRadious, position.y + defaultRadious};
}

float Ball::getRadious() {
	return radious;
}

void Ball::draw(RenderTarget &target, RenderStates state) const {
	target.draw(shape, state);
}

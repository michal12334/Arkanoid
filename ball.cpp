#include "ball.h"
#include "program.h"

using namespace sf;

Ball::Ball() {
	shape.setRadius(radious);
	shape.setFillColor(Color::Cyan);
	position.x = beginningPositionX;
	position.y = beginningPositionY;
	shape.setPosition(position);
	speed.x = beginningSpeedX;
	speed.y = beginningSpeedY;
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
		speed.x = speed.x > 0 ? speed.x : -speed.x;
	if(isCollisionRight)
		speed.x = speed.x > 0 ? -speed.x : speed.x;
	if(isCollisionTop)
		speed.y = speed.y > 0 ? speed.y : -speed.y;
	if(isCollisionBottom)
		speed.y = speed.y > 0 ? -speed.y : speed.y;

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

float Ball::getLeft() {
	return position.x;
}

float Ball::getRight() {
	return position.x + 2 * radious;
}

float Ball::getTop() {
	return position.y;
}

float Ball::getBottom() {
	return position.y + 2 * radious;
}

void Ball::draw(RenderTarget &target, RenderStates state) const {
	target.draw(shape, state);
}

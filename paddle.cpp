#include "paddle.h"
#include "program.h"

using namespace sf;

Paddle::Paddle() {
	position.x = defaultBeginningPositionX;
	position.y = defaultBeginningPositionY;
	rectangle.setPosition(position);
	rectangle.setSize(Vector2f{(float) defaultWidth, (float) defaultHeight});
	rectangle.setFillColor(Color::Red);
	setSpeed(defaultSpeed);
}

void Paddle::update() {
	float move = 0;
	if(isLeftKeyPressed()) {
		move -= speed;
	}
	if(isRightKeyPressed()) {
		move += speed;
	}
	move *= Program::getDeltaTime();
	position.x += move;
	rectangle.setPosition(position);
}

float Paddle::getLeft() {
	return position.x;
}

float Paddle::getRight() {
	return position.x + defaultWidth;
}

float Paddle::getBottom() {
	return position.y + defaultHeight;
}

float Paddle::getTop() {
	return position.y;
}

void Paddle::setSize(Vector2f size) {
	rectangle.setSize(size);
}

void Paddle::setPosition(Vector2f position) {
	this->position = position;
	rectangle.setPosition(position);
}

void Paddle::setSpeed(float speed) {
	this->speed = speed;
}

Vector2f Paddle::getPosition() {
	return position;
}

Vector2f Paddle::getSize() {
	return rectangle.getSize();
}

void Paddle::draw(RenderTarget &target, RenderStates state) const {
	target.draw(rectangle, state);
}

bool Paddle::isLeftKeyPressed() {
	return Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left);
}

bool Paddle::isRightKeyPressed() {
	return Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right);
}

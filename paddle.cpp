#include "paddle.h"
#include "program.h"

using namespace sf;

Paddle::Paddle() {
	position.x = beginningPositionX;
	position.y = beginningPositionY;
	rectangle.setPosition(position);
	rectangle.setSize(Vector2f{(float) width, (float) height});
	rectangle.setFillColor(Color::Red);
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
	return position.x + width;
}

float Paddle::getBottom() {
	return position.y + height;
}

float Paddle::getTop() {
	return position.y;
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

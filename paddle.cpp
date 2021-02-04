#include "paddle.h"
#include "program.h"

using namespace sf;

Paddle::Paddle() {
	position.x = Program::PADDLE_BEGINNING_POSITION_X;
	position.y = Program::PADDLE_BEGINNING_POSITION_Y;
	rectangle.setPosition(position);
	rectangle.setSize(Vector2f{(float) Program::PADDLE_WIDTH, (float) Program::PADDLE_HEIGHT});
	rectangle.setFillColor(Color::Red);
}

void Paddle::update() {
	float move = 0;
	if(isLeftKeyPressed()) {
		move -= Program::paddleSpeed;
	}
	if(isRightKeyPressed()) {
		move += Program::paddleSpeed;
	}
	move *= Program::getDeltaTime();
	position.x += move;
	rectangle.setPosition(position);
}

float Paddle::getLeft() {
	return position.x;
}

float Paddle::getRight() {
	return position.x + Program::PADDLE_WIDTH;
}

float Paddle::getBottom() {
	return position.y + Program::PADDLE_HEIGHT;
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

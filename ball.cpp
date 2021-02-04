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
}

void Ball::update() {
	position.x += speed.x * Program::getDeltaTime();
	position.y += speed.y * Program::getDeltaTime();
	shape.setPosition(position);
}

void Ball::draw(RenderTarget &target, RenderStates state) const {
	target.draw(shape, state);
}

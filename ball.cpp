#include "ball.h"
#include "program.h"

using namespace sf;

Ball::Ball() {
	shape.setRadius(RADIOUS);
	shape.setFillColor(Color::Cyan);
	position.x = BEGINNING_POSITION_X;
	position.y = BEGINNING_POSITION_Y;
	shape.setPosition(position);
	speed.x = BEGINNING_SPEED_X;
	speed.y = BEGINNING_SPEED_Y;
}

void Ball::update() {
	position.x += speed.x * Program::getDeltaTime();
	position.y += speed.y * Program::getDeltaTime();
	shape.setPosition(position);
}

void Ball::draw(RenderTarget &target, RenderStates state) const {
	target.draw(shape, state);
}

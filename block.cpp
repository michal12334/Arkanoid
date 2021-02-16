#include "block.h"

using namespace sf;

Block::Block(Vector2f position) {
	this->position = position;
	size = Vector2f{(float) DEFAULT_SIZE, (float) DEFAULT_SIZE};
	shape.setSize(size);
	shape.setPosition(position);
	shape.setFillColor(Color::Green);
	enable = true;
}

Block::Block(Vector2f position, Vector2f size) {
	this->position = position;
	this->size = size;
	shape.setSize(size);
	shape.setPosition(position);
	shape.setFillColor(Color::Green);
	enable = true;
}

void Block::setEnable(bool value) {
	enable = value;
}

bool Block::getEnable() {
	return enable;
}

float Block::getLeft() {
	return position.x;
}

float Block::getRight() {
	return position.x + size.x;
}

float Block::getTop() {
	return position.y;
}

float Block::getBottom() {
	return position.y + size.y;
}

void Block::setPosition(Vector2f position) {
	this->position = position;
	shape.setPosition(position);
}

void Block::setSize(Vector2f size) {
	this->size = size;
	shape.setSize(size);
}

Vector2f Block::getPosition() {
	return position;
}

Vector2f Block::getSize() {
	return size;
}

void Block::draw(RenderTarget &target, RenderStates state) const {
	if(enable)
		target.draw(shape, state);
}

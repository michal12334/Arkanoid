#include "oneColorButton.h"

using namespace sf;

OneColorButton::OneColorButton() :OneColorButton(Color::White) {}

OneColorButton::OneColorButton(sf::Color color) {
	shape.setFillColor(color);
}

void OneColorButton::setPosition(sf::Vector2f position) {
	this->position = position;
	shape.setPosition(position);
}

void OneColorButton::setSize(sf::Vector2f size) {
	this->size = size;
	shape.setSize(size);
}

void OneColorButton::update() {
}

void OneColorButton::draw(RenderTarget &target, RenderStates state) const {
	target.draw(shape, state);
}

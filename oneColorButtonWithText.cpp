#include "oneColorButtonWithText.h"

using namespace sf;

OneColorButtonWithText::OneColorButtonWithText() :OneColorButton() {}

OneColorButtonWithText::OneColorButtonWithText(Color color, Text text) :OneColorButton(color) {
	this->text = text;
}

void OneColorButtonWithText::update() {}

void OneColorButtonWithText::setTextPosition(Vector2f position) {
	textPosition = position;
	Vector2f realTextPosition;
	realTextPosition.x = textPosition.x + this->position.x;
	realTextPosition.y = textPosition.y + this->position.y;
	text.setPosition(realTextPosition);
}

void OneColorButtonWithText::setPosition(Vector2f position) {
	this->position = position;
	this->shape.setPosition(position);
	Vector2f realTextPosition;
	realTextPosition.x = textPosition.x + this->position.x;
	realTextPosition.y = textPosition.y + this->position.y;
	text.setPosition(realTextPosition);
}

void OneColorButtonWithText::draw(RenderTarget &target, RenderStates state) const {
	target.draw(shape, state);
	target.draw(text, state);
}

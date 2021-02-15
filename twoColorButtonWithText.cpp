#include "twoColorButtonWithText.h"

using namespace sf;

TwoColorButtonWithText::TwoColorButtonWithText() :TwoColorButton() {}

TwoColorButtonWithText::TwoColorButtonWithText(Color color1, Color color2, Text text) :TwoColorButton(color1, color2) {
	this->text = text;
}

void TwoColorButtonWithText::setTextPosition(Vector2f position) {
	textPosition = position;
	Vector2f realTextPosition;
	realTextPosition.x = textPosition.x + this->position.x;
	realTextPosition.y = textPosition.y + this->position.y;
	text.setPosition(realTextPosition);
}

void TwoColorButtonWithText::setPosition(Vector2f position) {
	this->position = position;
	this->shape.setPosition(position);
	Vector2f realTextPosition;
	realTextPosition.x = textPosition.x + this->position.x;
	realTextPosition.y = textPosition.y + this->position.y;
	text.setPosition(realTextPosition);
}

void TwoColorButtonWithText::draw(RenderTarget &target, RenderStates state) const {
	target.draw(shape, state);
	target.draw(text, state);
}

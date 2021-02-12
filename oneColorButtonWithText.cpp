#include "oneColorButtonWithText.h"

using namespace sf;

OneColorButtonWithText::OneColorButtonWithText() :OneColorButton() {}

OneColorButtonWithText::OneColorButtonWithText(Color color, Text text) :OneColorButton(color) {
	this->text = text;
}

void OneColorButtonWithText::update() {}

void OneColorButtonWithText::draw(RenderTarget &target, RenderStates state) const {
	target.draw(shape, state);
	target.draw(text, state);
}

#include "twoColorButton.h"

using namespace sf;

TwoColorButton::TwoColorButton() :TwoColorButton(Color::Red, Color::Green) {}

TwoColorButton::TwoColorButton(Color color1, Color color2) :OneColorButton(color1) {
	this->color1 = color1;
	this->color2 = color2;
}

void TwoColorButton::update() {
	if(isMouseInsideButton())
		shape.setFillColor(color2);
	else
		shape.setFillColor(color1);
}

void TwoColorButton::draw(RenderTarget &target, RenderStates state) const {
	target.draw(shape, state);
}

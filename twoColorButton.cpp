#include "twoColorButton.h"

using namespace sf;

TwoColorButton::TwoColorButton() :TwoColorButton(Color::Red, Color::Green) {}

TwoColorButton::TwoColorButton(Color color1, Color color2) :OneColorButton(color1) {
	this->color1 = color1;
	this->color2 = color2;
}

void TwoColorButton::update() {
	if(isMouseInsideButton())
		shape.setFillColor(color1);
	else
		shape.setFillColor(color2);
}
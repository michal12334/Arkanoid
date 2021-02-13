#include "button.h"
#include "program.h"

using namespace sf;

bool Button::mouseLeftButtonPressed = false;

void Button::updateMouseLeftButtonPressed() {
	if(Mouse::isButtonPressed(Mouse::Left))
		mouseLeftButtonPressed = true;
	else
		mouseLeftButtonPressed = false;
}

bool Button::isClicked() {
	return isMouseInsideButton() && isMouseLeftButtonPressed();
}

bool Button::isMouseInsideButton() {
	Vector2i mousePosition = Mouse::getPosition(*Program::window);
	return mousePosition.x >= getLeft() && mousePosition.x <= getRight()
		&& mousePosition.y >= getTop() && mousePosition.y <= getBottom();
}

bool Button::isMouseLeftButtonPressed() {
	return Mouse::isButtonPressed(Mouse::Left) && !mouseLeftButtonPressed;
}

int Button::getLeft() {
	return position.x;
}

int Button::getRight() {
	return position.x + size.x;
}

int Button::getTop() {
	return position.y;
}

int Button::getBottom() {
	return position.y + size.y;
}

void Button::setPosition(Vector2f position) {
	this->position = position;
}

void Button::setSize(Vector2f size) {
	this->size = size;
}

#include "spriteButton.h"

using namespace sf;
using namespace std;

SpriteButton::SpriteButton(string sprite1Name) {
	sprite1Enable = true;
	sprite2Enable = false;
	enableSprite = 1;
	texture1.loadFromFile(sprite1Name);
	sprite1.setTexture(texture1);
}

SpriteButton::SpriteButton(string sprite1Name, string sprite2Name) {
	sprite1Enable = true;
	sprite2Enable = true;
	enableSprite = 1;
	texture1.loadFromFile(sprite1Name);
	texture2.loadFromFile(sprite2Name);
	sprite1.setTexture(texture1);
	sprite2.setTexture(texture2);
}

void SpriteButton::update() {
	if(isMouseInsideButton() && sprite1Enable)
		enableSprite = 2;
	else
		enableSprite = 1;
}

void SpriteButton::setPosition(Vector2f position) {
	this->position = position;
	sprite1.setPosition(position);
	sprite2.setPosition(position);
}

void SpriteButton::draw(RenderTarget &target, RenderStates state) const {
	switch(enableSprite) {
	case 1: target.draw(sprite1, state); break;
	case 2: target.draw(sprite2, state); break;
	}
}

#include "page.h"

using namespace sf;
using namespace std;

Page::Page() :Page("PAGE") {}

Page::Page(string textString) {
	setFont("fonts/arial.ttf");
	setTextSize(60);
	setTextString(textString);
	setTextColor(Color::White);
	setTextPosition(Vector2f{200.0f, 200.0f});
}

void Page::setFont(string fontName) {
	font.loadFromFile(fontName);
	text.setFont(font);
}

void Page::setTextSize(int textSize) {
	text.setCharacterSize(textSize);
}

void Page::setTextString(string textString) {
	text.setString(textString);
}

void Page::setTextColor(Color textColor) {
	text.setFillColor(textColor);
}

void Page::setTextPosition(Vector2f position) {
	text.setPosition(position);
}

void Page::draw(RenderTarget &target, RenderStates state) const {
	target.draw(text, state);
}

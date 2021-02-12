#pragma once

#include "oneColorButton.h"

class OneColorButtonWithText :public OneColorButton {
public:
	OneColorButtonWithText();
	OneColorButtonWithText(sf::Color color, sf::Text text);
	void update();
	void setTextPosition(sf::Vector2f position);
	void setPosition(sf::Vector2f position);

private:
	void draw(sf::RenderTarget &target, sf::RenderStates state) const override;
	sf::Text text;
	sf::Vector2f textPosition;
};

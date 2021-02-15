#pragma once

#include "twoColorButton.h"

class TwoColorButtonWithText :public TwoColorButton {
public:
	TwoColorButtonWithText();
	TwoColorButtonWithText(sf::Color color1, sf::Color color2, sf::Text text);
	void setTextPosition(sf::Vector2f position);
	void setPosition(sf::Vector2f position);

private:
	void draw(sf::RenderTarget &target, sf::RenderStates state) const override;
	sf::Text text;
	sf::Vector2f textPosition;
};

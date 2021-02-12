#pragma once

#include "oneColorButton.h"

class OneColorButtonWithText :public OneColorButton {
public:
	OneColorButtonWithText();
	OneColorButtonWithText(sf::Color color, sf::Text text);
	void update();

private:
	void draw(sf::RenderTarget &target, sf::RenderStates state) const override;
	sf::Text text;
};

#pragma once

#include "oneColorButton.h"

class TwoColorButton :public OneColorButton {
public:
	TwoColorButton();
	TwoColorButton(sf::Color color1, sf::Color color2);
	void update();

private:
	void draw(sf::RenderTarget &target, sf::RenderStates state) const override;
	sf::Color color1;
	sf::Color color2;
};

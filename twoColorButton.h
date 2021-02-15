#pragma once

#include "oneColorButton.h"

class TwoColorButton :public OneColorButton {
public:
	TwoColorButton();
	TwoColorButton(sf::Color color1, sf::Color color2);
	void update();

private:
	sf::Color color1;
	sf::Color color2;
};

#pragma once

#include "menu.h"
#include "oneColorButtonWithText.h"

class PauseMenu :public Menu {
public:
	PauseMenu();
	~PauseMenu();
	void update();
	void draw();

private:
	Button *playButton;
	Button *exitButton;

	sf::Font font;
	sf::Text pauseMenuText;
	sf::Text playButtonText;
	sf::Text exitButtonText;
	sf::Color buttonColor;
	sf::Color buttonTextColor;
	const int BUTTON_TEXT_SIZE{40};
	void setTexts();
	void setFont();
	void setPauseMenuText();
	void setPlayButtonText();
	void setExitButtonText();
};

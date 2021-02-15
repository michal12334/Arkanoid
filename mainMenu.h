#pragma once

#include "menu.h"
#include "oneColorButtonWithText.h"
#include "twoColorButtonWithText.h"

class MainMenu :public Menu {
public:
	MainMenu();
	~MainMenu();
	void update();
	void draw();

private:
	Button *playButton;
	Button *chooseMapButton;
	Button *exitButton;

	sf::Font font;
	sf::Text mainMenuText;
	sf::Text playButtonText;
	sf::Text chooseMapButtonText;
	sf::Text exitButtonText;
	sf::Color buttonColor1;
	sf::Color buttonColor2;
	sf::Color buttonTextColor;
	const int BUTTON_TEXT_SIZE{40};
	void setTexts();
	void setFont();
	void setMainMenuText();
	void setPlayButtonText();
	void setChooseMapButtonText();
	void setExitButtonText();
};

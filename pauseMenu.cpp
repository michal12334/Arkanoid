#include "pauseMenu.h"
#include "program.h"

using namespace sf;

PauseMenu::PauseMenu() {
	buttonColor1 = Color::Red;
	buttonColor2 = Color::Green;
	buttonTextColor = Color::Black;
	setTexts();

	TwoColorButtonWithText *playButton = new TwoColorButtonWithText(buttonColor1, buttonColor2, playButtonText);
	TwoColorButtonWithText *exitButton = new TwoColorButtonWithText(buttonColor1, buttonColor2, exitButtonText);

	playButton->setTextPosition(Vector2f{100.0f, 23.0f});
	exitButton->setTextPosition(Vector2f{5.0f, 29.0f});

	playButton->setPosition(Vector2f{250.0f, 350.0f});
	playButton->setSize(Vector2f{300.0f, 100.0f});
	exitButton->setPosition(Vector2f{250.0f, 600.0f});
	exitButton->setSize(Vector2f{300.0f, 100.0f});

	this->playButton = playButton;
	this->exitButton = exitButton;
}

PauseMenu::~PauseMenu() {
	delete playButton;
	delete exitButton;
}

void PauseMenu::update() {
	if(playButton->isClicked()) {
		Program::status = Program::Status::game;
	}
	if(exitButton->isClicked()) {
		Program::status = Program::Status::mainMenu;
	}
	playButton->update();
	exitButton->update();
}

void PauseMenu::draw() {
	Program::window->draw(*playButton);
	Program::window->draw(*exitButton);
	Program::window->draw(pauseMenuText);
}

void PauseMenu::setTexts() {
	setFont();
	setPauseMenuText();
	setPlayButtonText();
	setExitButtonText();
}

void PauseMenu::setFont() {
	font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf");
}

void PauseMenu::setPauseMenuText() {
	pauseMenuText.setFont(font);
	pauseMenuText.setString("PAUSE MENU");
	pauseMenuText.setCharacterSize(100);
	pauseMenuText.setFillColor(Color::White);
	pauseMenuText.setPosition(Vector2f{75.0f, 40.0f});
}

void PauseMenu::setPlayButtonText() {
	playButtonText.setFont(font);
	playButtonText.setString("PLAY");
	playButtonText.setCharacterSize(BUTTON_TEXT_SIZE);
	playButtonText.setFillColor(buttonTextColor);
}

void PauseMenu::setExitButtonText() {
	exitButtonText.setFont(font);
	exitButtonText.setString("EXIT TO MAIN MENU");
	exitButtonText.setCharacterSize(30);
	exitButtonText.setFillColor(buttonTextColor);
}

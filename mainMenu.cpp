#include "mainMenu.h"
#include "program.h"
#include <string>

using namespace sf;
using namespace std;

MainMenu::MainMenu() {
	buttonColor = Color::Red;
	buttonTextColor = Color::Black;
	setTexts();

	OneColorButtonWithText *playButton = new OneColorButtonWithText(buttonColor, playButtonText);
	OneColorButtonWithText *chooseMapButton = new OneColorButtonWithText(buttonColor, chooseMapButtonText);
	OneColorButtonWithText *exitButton = new OneColorButtonWithText(buttonColor, exitButtonText);

	playButton->setTextPosition(Vector2f{100.0f, 23.0f});
	chooseMapButton->setTextPosition(Vector2f{15.0f, 23.0f});
	exitButton->setTextPosition(Vector2f{100.0f, 23.0f});
	
	playButton->setPosition(Vector2f{250.0f, 350.0f});
	playButton->setSize(Vector2f{300.0f, 100.0f});
	chooseMapButton->setPosition(Vector2f{250.0f, 500.0f});
	chooseMapButton->setSize(Vector2f{300.0f, 100.0f});
	exitButton->setPosition(Vector2f{250.0f, 650.0f});
	exitButton->setSize(Vector2f{300.0f, 100.0f});

	this->playButton = playButton;
	this->chooseMapButton = chooseMapButton;
	this->exitButton = exitButton;
}

void MainMenu::setTexts() {
	setFont();
	setPlayButtonText();
	setChooseMapButtonText();
	setExitButtonText();
}

void MainMenu::setFont() {
	font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf");
}

void MainMenu::setPlayButtonText() {
	playButtonText.setFont(font);
	playButtonText.setString("PLAY");
	playButtonText.setCharacterSize(BUTTON_TEXT_SIZE);
	playButtonText.setFillColor(buttonTextColor);
}

void MainMenu::setChooseMapButtonText() {
	chooseMapButtonText.setFont(font);
	chooseMapButtonText.setString("CHOOSE MAP");
	chooseMapButtonText.setCharacterSize(BUTTON_TEXT_SIZE);
	chooseMapButtonText.setFillColor(buttonTextColor);
}

void MainMenu::setExitButtonText() {
	exitButtonText.setFont(font);
	exitButtonText.setString("EXIT");
	exitButtonText.setCharacterSize(BUTTON_TEXT_SIZE);
	exitButtonText.setFillColor(buttonTextColor);
}

void MainMenu::update() {
	if(playButton->isClicked()) {
		Program::status = Program::Status::game;
	}
	if(exitButton->isClicked()) {
		Program::status = Program::Status::exit;
	}
}

void MainMenu::draw() {
	Program::window->draw(*playButton);
	Program::window->draw(*chooseMapButton);
	Program::window->draw(*exitButton);
}

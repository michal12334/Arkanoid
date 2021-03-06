#include "mainMenu.h"
#include "program.h"
#include <string>

using namespace sf;
using namespace std;

MainMenu::MainMenu() {
	buttonColor1 = Color::Red;
	buttonColor2 = Color::Green;
	buttonTextColor = Color::Black;
	setTexts();

	TwoColorButtonWithText *playButton = new TwoColorButtonWithText(buttonColor1, buttonColor2, playButtonText);
	TwoColorButtonWithText *chooseMapButton = new TwoColorButtonWithText(buttonColor1, buttonColor2, chooseMapButtonText);
	TwoColorButtonWithText *exitButton = new TwoColorButtonWithText(buttonColor1, buttonColor2, exitButtonText);

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

MainMenu::~MainMenu() {
	delete playButton;
	delete chooseMapButton;
	delete exitButton;
}

void MainMenu::setTexts() {
	setFont();
	setMainMenuText();
	setPlayButtonText();
	setChooseMapButtonText();
	setExitButtonText();
}

void MainMenu::setFont() {
	font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf");
}

void MainMenu::setMainMenuText() {
	mainMenuText.setFont(font);
	mainMenuText.setString("MENU");
	mainMenuText.setCharacterSize(100);
	mainMenuText.setFillColor(Color::White);
	mainMenuText.setPosition(Vector2f{255.0f, 40.0f});
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
	if(chooseMapButton->isClicked()) {
		Program::status = Program::Status::mapChooseMenu;
	}
	playButton->update();
	chooseMapButton->update();
	exitButton->update();
}

void MainMenu::draw() {
	Program::window->draw(*playButton);
	Program::window->draw(*chooseMapButton);
	Program::window->draw(*exitButton);
	Program::window->draw(mainMenuText);
}

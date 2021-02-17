#include "mapChooseMenu.h"
#include "program.h"

using namespace sf;

MapChooseMenu::MapChooseMenu() {
	currentMap = Map::currentMap - 1;
	Map *map = new Map1;
	mapDraws.push_back(new MapDraw{map});
	delete map;
	for(int i = 0; i < NUMBER_OF_MAPS; i++) {
		mapDraws[i]->setPosition(Vector2f{200.0f, 150.0f});
		mapDraws[i]->setSize(Vector2f{400.0f, 400.0f});
	}

	TwoColorButton *nextMapButton = new TwoColorButton(Color{50, 50, 50}, Color{100, 100, 100});
	TwoColorButton *previousMapButton = new TwoColorButton(Color{50, 50, 50}, Color{100, 100, 100});
	nextMapButton->setSize(Vector2f{150.0f, 400.0f});
	previousMapButton->setSize(Vector2f{150.0f, 400.0f});
	nextMapButton->setPosition(Vector2f{650.0f, 200.0f});
	previousMapButton->setPosition(Vector2f{0.0f, 200.0f});

	font.loadFromFile("fonts/arial.ttf");
	text.setFont(font);
	text.setFillColor(Color::Black);
	text.setString("SELECT");
	text.setCharacterSize(60);

	TwoColorButtonWithText *selectMapButton = new TwoColorButtonWithText(Color::Red, Color::Green, text);
	selectMapButton->setPosition(Vector2f{250.0f, 650.0f});
	selectMapButton->setSize(Vector2f{300.0f, 100.0f});
	selectMapButton->setTextPosition(Vector2f{31.0f, 10.0f});

	this->nextMapButton = nextMapButton;
	this->previousMapButton = previousMapButton;
	this->selectMapButton = selectMapButton;
}

MapChooseMenu::~MapChooseMenu() {
	for(int i = 0; i < mapDraws.size(); i++) {
		delete mapDraws[i];
	}
	delete nextMapButton;
	delete previousMapButton;
	delete selectMapButton;
}

void MapChooseMenu::update() {
	nextMapButton->update();
	previousMapButton->update();
	selectMapButton->update();

	if(selectMapButton->isClicked()) {
		Map::currentMap = currentMap + 1;
		Program::status = Program::Status::mainMenu;
	}

	if(currentMap != 0 && previousMapButton->isClicked()) {
		currentMap--;
	}

	if(currentMap != NUMBER_OF_MAPS - 1 && nextMapButton->isClicked()) {
		currentMap++;
	}
}

void MapChooseMenu::draw() {
	Program::window->draw(*mapDraws[currentMap]);
	if(currentMap != NUMBER_OF_MAPS - 1)
		Program::window->draw(*nextMapButton);
	if(currentMap != 0)
		Program::window->draw(*previousMapButton);
	Program::window->draw(*selectMapButton);
}

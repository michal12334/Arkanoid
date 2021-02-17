#pragma once

#include "menu.h"
#include "mapDraw.h"
#include "map1.h"
#include "map2.h"
#include <vector>
#include "twoColorButtonWithText.h"
#include "twoColorButton.h"

class MapChooseMenu :public Menu {
public:
	MapChooseMenu();
	~MapChooseMenu();
	void update();
	void draw();

private:
	int NUMBER_OF_MAPS{2};
	int currentMap;
	std::vector<MapDraw*> mapDraws;

	Button *nextMapButton;
	Button *previousMapButton;
	Button *selectMapButton;

	sf::Font font;
	sf::Text text;
};

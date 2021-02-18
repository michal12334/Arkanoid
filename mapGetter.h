#pragma once

#include "map.h"

class MapGetter {
public:
	Map *getMap(int number);
	int getNumberOfMaps();

private:
	const int NUMBER_OF_MAPS{3};
};

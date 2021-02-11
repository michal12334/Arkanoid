#pragma once

#include "blocks.h"

class Map {
public:
	virtual Blocks getBlocks() = 0;

	static const int DEFAULT_MAP;
	static int currentMap;
};

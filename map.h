#pragma once

#include "blocks.h"

class Map {
public:
	virtual std::vector<Block> getBlocksVector() = 0;

	static const int DEFAULT_MAP;
	static int currentMap;
};

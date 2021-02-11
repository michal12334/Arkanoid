#pragma once

#include "map.h"

class Map1 :public Map {
public:
	Map1();
	virtual Blocks getBlocks();

private:
	Blocks blocks;
};

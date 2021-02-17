#pragma once

#include "map.h"

class Map2 :public Map {
public:
	Map2();
	virtual Blocks getBlocks();
	virtual Ball getBall();
	virtual Paddle getPaddle();

private:
	Blocks blocks;
	Ball ball;
	Paddle paddle;
};

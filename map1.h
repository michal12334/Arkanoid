#pragma once

#include "map.h"

class Map1 :public Map {
public:
	Map1();
	virtual Blocks getBlocks();
	virtual Ball getBall();
	virtual Paddle getPaddle();

private:
	Blocks blocks;
	Ball ball;
	Paddle paddle;
};

#pragma once

#include "map.h"

class Map3 :public Map {
public:
	Map3();
	virtual Blocks getBlocks();
	virtual Ball getBall();
	virtual Paddle getPaddle();

private:
	Blocks blocks;
	Ball ball;
	Paddle paddle;
};

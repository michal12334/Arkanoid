#pragma once

#include "blocks.h"
#include "ball.h"
#include "paddle.h"

class Map {
public:
	virtual Blocks getBlocks() = 0;
	virtual Ball getBall() = 0;
	virtual Paddle getPaddle() = 0;

	static const int DEFAULT_MAP;
	static int currentMap;
};

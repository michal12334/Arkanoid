#pragma once

#include "paddle.h"
#include "ball.h"
#include "blocks.h"
#include "map.h"

class Game {
public:
	Game();
	void update();
	void draw();

private:
	Paddle paddle;
	Ball ball;
	Blocks blocks;
};

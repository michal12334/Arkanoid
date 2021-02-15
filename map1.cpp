#include "map1.h"

using namespace sf;

Map1::Map1() {
	const Vector2f BLOCK_SIZE = Vector2f{70.0f, 70.0f};
	for(int i = 0; i < 7; i++) {
		blocks.addBlock(Block{Vector2f{i * 100.f + 62.5f, 30.0f}, BLOCK_SIZE});
		if(i > 0 && i < 6) {
			blocks.addBlock(Block{Vector2f{i * 100.f + 62.5f, 120.0f}, BLOCK_SIZE});
		}
		if(i > 1 && i < 5) {
			blocks.addBlock(Block{Vector2f{i * 100.f + 62.5f, 210.0f}, BLOCK_SIZE});
		}
		if(i > 2 && i < 4) {
			blocks.addBlock(Block{Vector2f{i * 100.f + 62.5f, 300.0f}, BLOCK_SIZE});
		}
	}
}

Blocks Map1::getBlocks() {
	return blocks;
}

Ball Map1::getBall() {
	return ball;
}

Paddle Map1::getPaddle() {
	return paddle;
}

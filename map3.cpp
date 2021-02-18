#include "map3.h"

using namespace sf;

Map3::Map3() {
	const Vector2f BLOCK_SIZE = Vector2f{60.0f, 60.0f};
	blocks.addBlock(Block{Vector2f{170.0f, 10.0f}, BLOCK_SIZE});
	blocks.addBlock(Block{Vector2f{90.0f, 90.0f}, BLOCK_SIZE});
	blocks.addBlock(Block{Vector2f{170.0f, 90.0f}, BLOCK_SIZE});
	blocks.addBlock(Block{Vector2f{250.0f, 90.0f}, BLOCK_SIZE});
	blocks.addBlock(Block{Vector2f{10.0f, 170.0f}, BLOCK_SIZE});
	blocks.addBlock(Block{Vector2f{90.0f, 170.0f}, BLOCK_SIZE});
	blocks.addBlock(Block{Vector2f{170.0f, 170.0f}, BLOCK_SIZE});
	blocks.addBlock(Block{Vector2f{250.0f, 170.0f}, BLOCK_SIZE});
	blocks.addBlock(Block{Vector2f{330.0f, 170.0f}, BLOCK_SIZE});
	blocks.addBlock(Block{Vector2f{90.0f, 250.0f}, BLOCK_SIZE});
	blocks.addBlock(Block{Vector2f{170.0f, 250.0f}, BLOCK_SIZE});
	blocks.addBlock(Block{Vector2f{250.0f, 250.0f}, BLOCK_SIZE});
	blocks.addBlock(Block{Vector2f{170.0f, 330.0f}, BLOCK_SIZE});

	blocks.addBlock(Block{Vector2f{570.0f, 10.0f}, BLOCK_SIZE});
	blocks.addBlock(Block{Vector2f{490.0f, 90.0f}, BLOCK_SIZE});
	blocks.addBlock(Block{Vector2f{570.0f, 90.0f}, BLOCK_SIZE});
	blocks.addBlock(Block{Vector2f{650.0f, 90.0f}, BLOCK_SIZE});
	blocks.addBlock(Block{Vector2f{410.0f, 170.0f}, BLOCK_SIZE});
	blocks.addBlock(Block{Vector2f{490.0f, 170.0f}, BLOCK_SIZE});
	blocks.addBlock(Block{Vector2f{570.0f, 170.0f}, BLOCK_SIZE});
	blocks.addBlock(Block{Vector2f{650.0f, 170.0f}, BLOCK_SIZE});
	blocks.addBlock(Block{Vector2f{730.0f, 170.0f}, BLOCK_SIZE});
	blocks.addBlock(Block{Vector2f{490.0f, 250.0f}, BLOCK_SIZE});
	blocks.addBlock(Block{Vector2f{570.0f, 250.0f}, BLOCK_SIZE});
	blocks.addBlock(Block{Vector2f{650.0f, 250.0f}, BLOCK_SIZE});
	blocks.addBlock(Block{Vector2f{570.0f, 330.0f}, BLOCK_SIZE});
}

Blocks Map3::getBlocks() {
	return blocks;
}

Ball Map3::getBall() {
	return ball;
}

Paddle Map3::getPaddle() {
	return paddle;
}

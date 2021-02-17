#include "map2.h"

using namespace sf;

Map2::Map2() {
	const Vector2f BLOCK_SIZE = Vector2f{60.0f, 60.0f};
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 3; j++) {
			Block block(Vector2f{10.0f + i * 80.0f, 10.0f + j * 80.0f}, BLOCK_SIZE);
			int r = (i * 100) % 255;
			int g = (j * 200) % 255;
			int b = ((i + j) * 150) % 255;
			if(r < 120) r += 120;
			if(g < 120) g += 120;
			if(b < 120) b += 120;
			block.setColor(Color{(Uint8) r, (Uint8) g, (Uint8) b});
			blocks.addBlock(block);
		}
	}
}

Blocks Map2::getBlocks() {
	return blocks;
}

Ball Map2::getBall() {
	return ball;
}

Paddle Map2::getPaddle() {
	return paddle;
}

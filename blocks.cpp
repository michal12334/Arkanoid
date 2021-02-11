#include "blocks.h"

using namespace sf;

void Blocks::addBlock(Block block) {
	blocks.push_back(block);
}

void Blocks::draw(RenderTarget &target, RenderStates state) const {
	for(const auto& block : blocks) {
		target.draw(block, state);
	}
}

#include "blocks.h"

using namespace sf;

void Blocks::addBlock(Block block) {
	blocks.push_back(block);
}

Block *Blocks::getBlock(int index) {
	return &blocks[index];
}

int Blocks::size() {
	return blocks.size();
}

void Blocks::update() {
	for(int i = 0; i < size(); i++) {
		if(!blocks[i].getEnable()) {
			blocks.erase(blocks.begin() + i);
		}
	}
}

void Blocks::draw(RenderTarget &target, RenderStates state) const {
	for(const auto& block : blocks) {
		target.draw(block, state);
	}
}

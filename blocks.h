#pragma once

#include "block.h"
#include <vector>

class Blocks :public sf::Drawable {
public:
	void addBlock(Block block);

private:
	void draw(sf::RenderTarget &target, sf::RenderStates state) const override;
	std::vector<Block> blocks;

};

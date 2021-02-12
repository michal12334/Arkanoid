#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Menu {
public:
	virtual void update() = 0;
	virtual void draw() = 0;
};

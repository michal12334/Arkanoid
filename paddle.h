#pragma once

#include "SFML/Graphics.hpp"

class Paddle :public sf::Drawable{
public:
	Paddle();
	void update();

private:
	void draw(sf::RenderTarget &target, sf::RenderStates state) const override;
	sf::RectangleShape rectangle;
	sf::Vector2f position;

	bool isLeftKeyPressed();
	bool isRightKeyPressed();
};

#pragma once

#include "SFML/Graphics.hpp"

class Paddle :public sf::Drawable{
public:
	Paddle();
	void update();
	float getLeft();
	float getRight();
	float getTop();
	float getBottom();

	static int width;
	static int height;
	static int beginningPositionX;
	static int beginningPositionY;
	static float speed;

private:
	void draw(sf::RenderTarget &target, sf::RenderStates state) const override;
	sf::RectangleShape rectangle;
	sf::Vector2f position;

	bool isLeftKeyPressed();
	bool isRightKeyPressed();
};

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

	static const int WIDTH;
	static const int HEIGHT;
	static const int BEGINNING_POSITION_X;
	static const int BEGINNING_POSITION_Y;
	static float speed;

private:
	void draw(sf::RenderTarget &target, sf::RenderStates state) const override;
	sf::RectangleShape rectangle;
	sf::Vector2f position;

	bool isLeftKeyPressed();
	bool isRightKeyPressed();
};

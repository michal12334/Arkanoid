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

	static int defaultWidth;
	static int defaultHeight;
	static int defaultBeginningPositionX;
	static int defaultBeginningPositionY;
	static float defaultSpeed;

	void setSize(sf::Vector2f size);
	void setPosition(sf::Vector2f position);
	void setSpeed(float speed);

private:
	void draw(sf::RenderTarget &target, sf::RenderStates state) const override;
	sf::RectangleShape rectangle;
	sf::Vector2f position;
	float speed;

	bool isLeftKeyPressed();
	bool isRightKeyPressed();
};

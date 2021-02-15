#pragma once

#include <SFML/Graphics.hpp>

class Ball :public sf::Drawable {
public:
	Ball();
	void update();
	float getLeft();
	float getRight();
	float getTop();
	float getBottom();
	sf::Vector2f getCenter();
	float getRadious();

	void setCollisionLeft(bool value);
	void setCollisionRight(bool value);
	void setCollisionTop(bool value);
	void setCollisionBottom(bool value);

	void setRadious(float radious);
	void setPosition(sf::Vector2f position);
	void setSpeed(sf::Vector2f speed);

	static int defaultRadious;
	static int defaultBeginningPositionX;
	static int defaultBeginningPositionY;
	static int defaultBeginningSpeedX;
	static int defaultBeginningSpeedY;

private:
	void draw(sf::RenderTarget &target, sf::RenderStates state) const override;
	sf::CircleShape shape;
	sf::Vector2f position;
	sf::Vector2f speed;
	float radious;

	bool isCollisionLeft;
	bool isCollisionRight;
	bool isCollisionTop;
	bool isCollisionBottom;

	void move();
	void executeCollsion();
};

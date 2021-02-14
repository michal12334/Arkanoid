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

	static int radious;
	static int beginningPositionX;
	static int beginningPositionY;
	static int beginningSpeedX;
	static int beginningSpeedY;

private:
	void draw(sf::RenderTarget &target, sf::RenderStates state) const override;
	sf::CircleShape shape;
	sf::Vector2f position;
	sf::Vector2f speed;

	bool isCollisionLeft;
	bool isCollisionRight;
	bool isCollisionTop;
	bool isCollisionBottom;

	void move();
	void executeCollsion();
};

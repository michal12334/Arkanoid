#pragma once

#include <SFML/Graphics.hpp>

class Ball :public sf::Drawable {
public:
	Ball();
	void update();

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
};

#pragma once

#include <SFML/Graphics.hpp>

class Ball :public sf::Drawable {
public:
	Ball();
	void update();

	static const int RADIOUS;
	static const int BEGINNING_POSITION_X;
	static const int BEGINNING_POSITION_Y;
	static const int BEGINNING_SPEED_X;
	static const int BEGINNING_SPEED_Y;

private:
	void draw(sf::RenderTarget &target, sf::RenderStates state) const override;
	sf::CircleShape shape;
	sf::Vector2f position;
	sf::Vector2f speed;
};

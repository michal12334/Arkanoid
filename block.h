#pragma once

#include <SFML/Graphics.hpp>

class Block :public sf::Drawable {
public:
	Block(sf::Vector2f position);
	Block(sf::Vector2f position, sf::Vector2f size);
	void setEnable(bool value);
	bool getEnable();
	float getLeft();
	float getRight();
	float getTop();
	float getBottom();

	static const int DEFAULT_SIZE;

private:
	void draw(sf::RenderTarget &target, sf::RenderStates state) const override;
	bool enable;
	sf::Vector2f position;
	sf::Vector2f size;
	sf::RectangleShape shape;
};

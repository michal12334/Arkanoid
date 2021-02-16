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

	void setPosition(sf::Vector2f position);
	void setSize(sf::Vector2f size);
	sf::Vector2f getPosition();
	sf::Vector2f getSize();

private:
	void draw(sf::RenderTarget &target, sf::RenderStates state) const override;
	bool enable;
	sf::Vector2f position;
	sf::Vector2f size;
	sf::RectangleShape shape;
};

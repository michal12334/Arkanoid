#pragma once

#include <SFML/Graphics.hpp>

class Button :public sf::Drawable {
public:
	bool isClicked();
	void setPosition(sf::Vector2f position);
	void setSize(sf::Vector2f size);

	static bool mouseLeftButtonPressed;
	static void updateMouseLeftButtoPressed();

private:
	//void draw(sf::RenderTarget &target, sf::RenderStates state) const override;
	sf::Vector2f position;
	sf::Vector2f size;

	bool isMouseInsideButton();
	bool isMouseLeftButtonPressed();

	int getLeft();
	int getRight();
	int getTop();
	int getBottom();
};

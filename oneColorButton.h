#pragma once

#include "button.h"

class OneColorButton :public Button {
public:
	OneColorButton();
	OneColorButton(sf::Color color);
	void setPosition(sf::Vector2f position);
	void setSize(sf::Vector2f size);
	virtual void update() = 0;

protected:
	sf::RectangleShape shape;

private:
	void draw(sf::RenderTarget &target, sf::RenderStates state) const override;
};

#pragma once

#include "button.h"
#include <string>

class SpriteButton :public Button {
public:
	SpriteButton(std::string sprite1Name);
	SpriteButton(std::string sprite1Name, std::string sprite2Name);
	void update();
	void setPosition(sf::Vector2f position);

private:
	void draw(sf::RenderTarget &target, sf::RenderStates state) const override;
	sf::Texture texture1;
	sf::Texture texture2;
	sf::Sprite sprite1;
	sf::Sprite sprite2;
	bool sprite1Enable;
	bool sprite2Enable;
	int enableSprite;
};

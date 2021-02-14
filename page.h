#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Page {
public:
	Page();
	Page(std::string textString);
	void setFont(std::string fontName);
	void setTextSize(int textSize);
	void setTextString(std::string textString);
	void setTextColor(sf::Color textColor);
	void setTextPosition(sf::Vector2f position);
	void update();
	void draw();

protected:
	sf::Font font;
	sf::Text text;
	float time;
	float timeToEnd;
};

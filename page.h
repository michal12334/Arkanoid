#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Page :public sf::Drawable {
public:
	Page();
	Page(std::string textString);
	void setFont(std::string fontName);
	void setTextSize(int textSize);
	void setTextString(std::string textString);
	void setTextColor(sf::Color textColor);
	void setTextPosition(sf::Vector2f position);

protected:
	sf::Font font;
	sf::Text text;

private:
	void draw(sf::RenderTarget &target, sf::RenderStates state) const override;
};

#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Program {
public:
	static sf::RenderWindow *window;
	static const std::string WINDOW_TITLE;
	static const int WINDOW_WIDTH;
	static const int WINDOW_HEIGHT;
	static int frameRateLimit;
	static float getDeltaTime();

	enum Status {
		game
	};
	static Status status;
};

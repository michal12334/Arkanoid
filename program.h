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

	static const int PADDLE_WIDTH;
	static const int PADDLE_HEIGHT;
	static const int PADDLE_BEGINNING_POSITION_X;
	static const int PADDLE_BEGINNING_POSITION_Y;
	static float paddleSpeed;
};

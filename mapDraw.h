#pragma once

#include "map.h"

class MapDraw :public sf::Drawable {
public:
	MapDraw(Map *map);
	void setMap(Map *map);
	void setPosition(sf::Vector2f position);
	void setSize(sf::Vector2f size);

private:
	void draw(sf::RenderTarget &target, sf::RenderStates state) const override;
	Ball ball;
	Paddle paddle;
	Blocks blocks;
	sf::Vector2f position;
	sf::Vector2f size;
	sf::Vector2f scale;

	sf::Vector2f oldScale;
	sf::Vector2f oldPosition;

	void setBall(Map *map);
	void setPaddle(Map *map);
	void setBlocks(Map *map);

	void setBall();
	void setPaddle();
	void setBlocks();
	void setBallPosition();
	void setBallSize();
	void setPaddlePosition();
	void setPaddleSize();
	void setBlocksPosition();
	void setBlocksSize();
};

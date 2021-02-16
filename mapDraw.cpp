#include "mapDraw.h"
#include "program.h"

using namespace sf;

MapDraw::MapDraw(Map *map) {
	setPosition(Vector2f{0, 0});
	setSize(Vector2f{(float) Program::WINDOW_WIDTH, (float) Program::WINDOW_HEIGHT});
	setMap(map);
}

void MapDraw::setMap(Map *map) {
	setBall(map);
	setPaddle(map);
	setBlocks(map);
}

void MapDraw::setBall(Map *map) {
	ball = map->getBall();
	setBall();
}

void MapDraw::setBall() {
	float r = ball.getRadious();
	r *= (scale.x + scale.y) / 2;
	ball.setRadious(r);
	sf::Vector2f p = ball.getPosition();
	p.x *= scale.x;
	p.y *= scale.y;
	p.x += position.x;
	p.y += position.y;
	ball.setPosition(p);
}

void MapDraw::setPaddle(Map *map) {
	paddle = map->getPaddle();
	setPaddle();
}

void MapDraw::setPaddle() {
	Vector2f s = paddle.getSize();
	s.x *= scale.x;
	s.y *= scale.y;
	paddle.setSize(s);
	sf::Vector2f p = paddle.getPosition();
	p.x *= scale.x;
	p.y *= scale.y;
	p.x += position.x;
	p.y += position.y;
	paddle.setPosition(p);
}

void MapDraw::setBlocks(Map *map) {
	blocks = map->getBlocks();
	setBlocks();
}

void MapDraw::setBlocks() {
	for(int i = 0; i < blocks.size(); i++) {
		Vector2f s = blocks.getBlock(i)->getSize();
		s.x *= scale.x;
		s.y *= scale.y;
		blocks.getBlock(i)->setSize(s);
		sf::Vector2f p = blocks.getBlock(i)->getPosition();
		p.x *= scale.x;
		p.y *= scale.y;
		p.x += position.x;
		p.y += position.y;
		blocks.getBlock(i)->setPosition(p);
	}
}

void MapDraw::setPosition(Vector2f position) {
	this->position = position;
	setBall();
	setPaddle();
	setBlocks();
}

void MapDraw::setSize(Vector2f size) {
	this->size = size;
	scale.x = size.x / Program::WINDOW_WIDTH;
	scale.y = size.y / Program::WINDOW_HEIGHT;
	setBall();
	setPaddle();
	setBlocks();
}

void MapDraw::draw(RenderTarget &target, RenderStates state) const {
	target.draw(ball, state);
	target.draw(paddle, state);
	target.draw(blocks, state);
}

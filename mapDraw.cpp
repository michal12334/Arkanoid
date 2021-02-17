#include "mapDraw.h"
#include "program.h"

using namespace sf;

MapDraw::MapDraw(Map *map) {
	oldScale = Vector2f{1.0f, 1.0f};
	oldPosition = Vector2f{0.0f, 0.0f};
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
	setBallSize();
	setBallPosition();
}

void MapDraw::setBallPosition() {
	Vector2f p = ball.getPosition();
	p.x -= oldPosition.x;
	p.y -= oldPosition.y;
	p.x /= oldScale.x;
	p.y /= oldScale.y;
	p.x *= scale.x;
	p.y *= scale.y;
	p.x += position.x;
	p.y += position.y;
	ball.setPosition(p);
}

void MapDraw::setBallSize() {
	float r = ball.getRadious();
	r /= (oldScale.x + oldScale.y) / 2;
	r *= (scale.x + scale.y) / 2;
	ball.setRadious(r);
}

void MapDraw::setPaddle(Map *map) {
	paddle = map->getPaddle();
	setPaddle();
}

void MapDraw::setPaddle() {
	setPaddleSize();
	setPaddlePosition();
}

void MapDraw::setPaddlePosition() {
	Vector2f p = paddle.getPosition();
	p.x -= oldPosition.x;
	p.y -= oldPosition.y;
	p.x /= oldScale.x;
	p.y /= oldScale.y;
	p.x *= scale.x;
	p.y *= scale.y;
	p.x += position.x;
	p.y += position.y;
	paddle.setPosition(p);
}

void MapDraw::setPaddleSize() {
	Vector2f s = paddle.getSize();
	s.x /= oldScale.x;
	s.y /= oldScale.y;
	s.x *= scale.x;
	s.y *= scale.y;
	paddle.setSize(s);
}

void MapDraw::setBlocks(Map *map) {
	blocks = map->getBlocks();
	setBlocks();
}

void MapDraw::setBlocks() {
	setBlocksSize();
	setBlocksPosition();
}

void MapDraw::setBlocksPosition() {
	for(int i = 0; i < blocks.size(); i++) {
		Vector2f p = blocks.getBlock(i)->getPosition();
		p.x -= oldPosition.x;
		p.y -= oldPosition.y;
		p.x /= oldScale.x;
		p.y /= oldScale.y;
		p.x *= scale.x;
		p.y *= scale.y;
		p.x += position.x;
		p.y += position.y;
		blocks.getBlock(i)->setPosition(p);
	}
}

void MapDraw::setBlocksSize() {
	for(int i = 0; i < blocks.size(); i++) {
		Vector2f s = blocks.getBlock(i)->getSize();
		s.x /= oldScale.x;
		s.y /= oldScale.y;
		s.x *= scale.x;
		s.y *= scale.y;
		blocks.getBlock(i)->setSize(s);
	}
}

void MapDraw::setPosition(Vector2f position) {
	this->position = position;
	setBall();
	setPaddle();
	setBlocks();
	oldPosition = position;
}

void MapDraw::setSize(Vector2f size) {
	this->size = size;
	scale.x = size.x / Program::WINDOW_WIDTH;
	scale.y = size.y / Program::WINDOW_HEIGHT;
	setBall();
	setPaddle();
	setBlocks();
	oldScale = scale;
}

void MapDraw::draw(RenderTarget &target, RenderStates state) const {
	target.draw(ball, state);
	target.draw(paddle, state);
	target.draw(blocks, state);
}

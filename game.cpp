#include "game.h"
#include "program.h"
#include "map1.h"
#include "map2.h"
#include "collisionChecker.h"
#include "mapGetter.h"

using namespace sf;

Game::Game() {
	MapGetter mapGetter;
	Map *currentMap = mapGetter.getMap(Map::currentMap);
	blocks = currentMap->getBlocks();
	ball = currentMap->getBall();
	paddle = currentMap->getPaddle();
	delete currentMap;
}

void Game::update() {
	CollisionChecker collisionChecker;
	bool isLost = false;

	for(int i = 0; i < blocks.size(); i++) {
		collisionChecker.checkCollisionBetweenBlockAndBall(blocks.getBlock(i), &ball);
	}
	collisionChecker.checkCollisionBetweenPaddleAndBall(&paddle, &ball);
	collisionChecker.checkCollisionBetweenBallAndTopLeftRightSidesOfWindow(&ball);
	collisionChecker.checkCollisionBetweenBallAndBottomSideOfWindow(&ball, isLost);

	paddle.update();
	ball.update();
	blocks.update();

	if(Keyboard::isKeyPressed(Keyboard::Escape)) {
		Program::status = Program::Status::pauseMenu;
	}

	if(isLost) {
		Program::status = Program::Status::youLostPage;
	}

	if(blocks.size() == 0) {
		Program::status = Program::Status::youWonPage;
	}
}

void Game::draw() {
	Program::window->draw(paddle);
	Program::window->draw(ball);
	Program::window->draw(blocks);
}

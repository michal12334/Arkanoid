#include "collisionChecker.h"
#include <iostream>

using namespace std;
using namespace sf;

void CollisionChecker::checkCollisionBetweenPaddleAndBall(Paddle *paddle, Ball *ball) {
	if(isBallHitBottomSideOfRectangle(ball, paddle)) {
		ball->setCollisionTop(true);
	}

	if(isBallHitTopSideOfRectangle(ball, paddle)) {
		ball->setCollisionBottom(true);
	}

	if(isBallHitRightSideOfRectangle(ball, paddle)) {
		ball->setCollisionLeft(true);
	}

	if(isBallHitLetfSideOfRectangle(ball, paddle)) {
		ball->setCollisionRight(true);
	}

	if(isBallHitLetfDownCornerOfRectangle(ball, paddle)) {
		ball->setCollisionRight(true);
		ball->setCollisionTop(true);

	}

	if(isBallHitRightDownCornerOfRectangle(ball, paddle)) {
		ball->setCollisionLeft(true);
		ball->setCollisionTop(true);
	}

	if(isBallHitLeftTopCornerOfRectangle(ball, paddle)) {
		ball->setCollisionRight(true);
		ball->setCollisionBottom(true);
	}

	if(isBallHitRightTopCornerOfRectangle(ball, paddle)) {
		ball->setCollisionLeft(true);
		ball->setCollisionBottom(true);
	}
}

void CollisionChecker::checkCollisionBetweenBlockAndBall(Block *block, Ball *ball) {
	if(isBallHitBottomSideOfRectangle(ball, block)) {
		ball->setCollisionTop(true);
		block->setEnable(false);
	}

	if(isBallHitTopSideOfRectangle(ball, block)) {
		ball->setCollisionBottom(true);
		block->setEnable(false);
	}

	if(isBallHitRightSideOfRectangle(ball, block)) {
		ball->setCollisionLeft(true);
		block->setEnable(false);
	}

	if(isBallHitLetfSideOfRectangle(ball, block)) {
		ball->setCollisionRight(true);
		block->setEnable(false);
	}

	if(isBallHitLetfDownCornerOfRectangle(ball, block)) {
		ball->setCollisionRight(true);
		ball->setCollisionTop(true);
		block->setEnable(false);
	}

	if(isBallHitRightDownCornerOfRectangle(ball, block)) {
		ball->setCollisionLeft(true);
		ball->setCollisionTop(true);
		block->setEnable(false);
	}

	if(isBallHitLeftTopCornerOfRectangle(ball, block)) {
		ball->setCollisionRight(true);
		ball->setCollisionBottom(true);
		block->setEnable(false);
	}

	if(isBallHitRightTopCornerOfRectangle(ball, block)) {
		ball->setCollisionLeft(true);
		ball->setCollisionBottom(true);
		block->setEnable(false);
	}
}

float CollisionChecker::distance2(Vector2f point1, Vector2f point2) {
	return (point1.x - point2.x) * (point1.x - point2.x) + (point1.y - point2.y) * (point1.y - point2.y);
}

template <class T> bool CollisionChecker::isBallHitLetfSideOfRectangle(Ball *ball, T *rectangle) {
	return ball->getLeft() <= rectangle->getLeft() && ball->getRight() >= rectangle->getLeft()
		&& ball->getCenter().y >= rectangle->getTop() && ball->getCenter().y <= rectangle->getBottom();
}

template <class T> bool CollisionChecker::isBallHitRightSideOfRectangle(Ball *ball, T *rectangle) {
	return ball->getLeft() <= rectangle->getRight() && ball->getRight() >= rectangle->getRight()
		&& ball->getCenter().y >= rectangle->getTop() && ball->getCenter().y <= rectangle->getBottom();
}

template <class T> bool CollisionChecker::isBallHitTopSideOfRectangle(Ball *ball, T *rectangle) {
	return ball->getBottom() >= rectangle->getTop() && ball->getTop() <= rectangle->getTop()
		&& ball->getCenter().x >= rectangle->getLeft() && ball->getCenter().x <= rectangle->getRight();
}

template <class T> bool CollisionChecker::isBallHitBottomSideOfRectangle(Ball *ball, T *rectangle) {
	return ball->getTop() <= rectangle->getBottom() && ball->getBottom() >= rectangle->getBottom()
		&& ball->getCenter().x >= rectangle->getLeft() && ball->getCenter().x <= rectangle->getRight();
}

template <class T> bool CollisionChecker::isBallHitLetfDownCornerOfRectangle(Ball *ball, T *rectangle) {
	Vector2f leftDownCorner;
	leftDownCorner.x = rectangle->getLeft();
	leftDownCorner.y = rectangle->getBottom();
	return isBallHitPoint(ball, leftDownCorner);
}

template <class T> bool CollisionChecker::isBallHitRightDownCornerOfRectangle(Ball *ball, T *rectangle) {
	Vector2f rightDownCorner;
	rightDownCorner.x = rectangle->getLeft();
	rightDownCorner.y = rectangle->getBottom();
	return isBallHitPoint(ball, rightDownCorner);
}

template <class T> bool CollisionChecker::isBallHitLeftTopCornerOfRectangle(Ball *ball, T *rectangle) {
	Vector2f leftTopCorner;
	leftTopCorner.x = rectangle->getLeft();
	leftTopCorner.y = rectangle->getBottom();
	return isBallHitPoint(ball, leftTopCorner);
}

template <class T> bool CollisionChecker::isBallHitRightTopCornerOfRectangle(Ball *ball, T *rectangle) {
	Vector2f rightTopCorner;
	rightTopCorner.x = rectangle->getLeft();
	rightTopCorner.y = rectangle->getBottom();
	return isBallHitPoint(ball, rightTopCorner);
}

bool CollisionChecker::isBallHitPoint(Ball *ball, Vector2f point) {
	return distance2(point, ball->getCenter()) <= ball->getRadious() * ball->getRadious();
}

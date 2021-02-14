#pragma once

#include "paddle.h"
#include "ball.h"
#include "block.h"

class CollisionChecker {
public:
	void checkCollisionBetweenPaddleAndBall(Paddle *paddle, Ball *ball);
	void checkCollisionBetweenBlockAndBall(Block *block, Ball *ball);
	void checkCollisionBetweenBallAndTopLeftRightSidesOfWindow(Ball *ball);
	void checkCollisionBetweenBallAndBottomSideOfWindow(Ball *ball, bool &result);

private:
	float distance2(sf::Vector2f point1, sf::Vector2f point2);
	template <class T> bool isBallHitLetfSideOfRectangle(Ball *ball, T *rectangle);
	template <class T> bool isBallHitRightSideOfRectangle(Ball *ball, T *rectangle);
	template <class T> bool isBallHitTopSideOfRectangle(Ball *ball, T *rectangle);
	template <class T> bool isBallHitBottomSideOfRectangle(Ball *ball, T *rectangle);
	template <class T> bool isBallHitLetfDownCornerOfRectangle(Ball *ball, T *rectangle);
	template <class T> bool isBallHitRightDownCornerOfRectangle(Ball *ball, T *rectangle);
	template <class T> bool isBallHitLeftTopCornerOfRectangle(Ball *ball, T *rectangle);
	template <class T> bool isBallHitRightTopCornerOfRectangle(Ball *ball, T *rectangle);
	bool isBallHitPoint(Ball *ball, sf::Vector2f point);
};

#include <iostream>
#include "program.h"
#include "game.h"
#include "paddle.h"
#include "ball.h"
#include "block.h"
#include "map.h"
#include "mainMenu.h"
#include "button.h"
#include "pauseMenu.h"
#include "youWonPage.h"
#include "youLostPage.h"
#include "mapChooseMenu.h"

using namespace std;
using namespace sf;

RenderWindow *Program::window = NULL;
const string Program::WINDOW_TITLE = "Arkanoid";
const int Program::WINDOW_WIDTH = 800;
const int Program::WINDOW_HEIGHT = 800;
int Program::frameRateLimit = 60;
Program::Status Program::status = Program::Status::mainMenu;

int Paddle::defaultWidth = 80;
int Paddle::defaultHeight = 20;
int Paddle::defaultBeginningPositionX = 360;
int Paddle::defaultBeginningPositionY = 600;
float Paddle::defaultSpeed = 250;

int Ball::defaultRadious = 10;
int Ball::defaultBeginningPositionX = 150;
int Ball::defaultBeginningPositionY = 600;
int Ball::defaultBeginningSpeedX = 180;
int Ball::defaultBeginningSpeedY = -180;

const int Block::DEFAULT_SIZE = 50;

const int Map::DEFAULT_MAP = 1;
int Map::currentMap = Map::DEFAULT_MAP;

int main() {
	Program::window = new RenderWindow(VideoMode{Program::WINDOW_WIDTH, Program::WINDOW_HEIGHT}, Program::WINDOW_TITLE);
	Program::window->setFramerateLimit(60);
	Game *game = NULL;
	Menu *mainMenu = NULL;
	Menu *pauseMenu = NULL;
	Menu *mapChooseMenu = NULL;
	Page *youWonPage = NULL;
	Page *youLostPage = NULL;
	bool isEnd = false;
	Event event;
	while(!isEnd) {
		Program::window->pollEvent(event);
		if(event.type == Event::Closed) {
			break;
		}

		Button::updateMouseLeftButtonPressed();

		Program::window->clear();

		switch(Program::status) {
		case Program::Status::game:
			if(game == NULL) {
				game = new Game();
			}
			if(mainMenu != NULL) {
				delete mainMenu;
				mainMenu = NULL;
			}
			if(pauseMenu != NULL) {
				delete pauseMenu;
				pauseMenu = NULL;
			}
			game->update();
			game->draw();
			break;

		case Program::Status::mainMenu:
			if(mainMenu == NULL) {
				mainMenu = new MainMenu();
			}
			if(game != NULL) {
				delete game;
				game = NULL;
			}
			if(pauseMenu != NULL) {
				delete pauseMenu;
				pauseMenu = NULL;
			}
			if(mapChooseMenu != NULL) {
				delete mapChooseMenu;
				mapChooseMenu = NULL;
			}
			if(youLostPage != NULL) {
				delete youLostPage;
				youLostPage = NULL;
			}
			if(youWonPage != NULL) {
				delete youWonPage;
				youWonPage = NULL;
			}
			mainMenu->update();
			mainMenu->draw();
			break;

		case Program::Status::pauseMenu:
			if(pauseMenu == NULL) {
				pauseMenu = new PauseMenu();
			}
			if(mainMenu != NULL) {
				delete mainMenu;
				mainMenu = NULL;
			}
			pauseMenu->update();
			pauseMenu->draw();
			break;

		case Program::Status::mapChooseMenu:
			if(mapChooseMenu == NULL) {
				mapChooseMenu = new MapChooseMenu();
			}
			if(mainMenu != NULL) {
				delete mainMenu;
				mainMenu = NULL;
			}
			mapChooseMenu->update();
			mapChooseMenu->draw();
			break;

		case Program::Status::youWonPage:
			if(youWonPage == NULL) {
				youWonPage = new YouWonPage();
			}
			if(game != NULL) {
				delete game;
				game = NULL;
			}
			youWonPage->update();
			youWonPage->draw();
			break;

		case Program::Status::youLostPage:
			if(youLostPage == NULL) {
				youLostPage = new YouLostPage();
			}
			if(game != NULL) {
				delete game;
				game = NULL;
			}
			youLostPage->update();
			youLostPage->draw();
			break;

		case Program::Status::exit:
			isEnd = true;
			break;
		}

		Program::window->display();
	}
	return 0;
}

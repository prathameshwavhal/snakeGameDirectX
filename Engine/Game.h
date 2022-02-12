#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Board.h"
#include "Snake.h"
#include "Goal.h"
#include "Obstacle.h"
#include <random>

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	Board b;
	Snake snake;
	Location delta_loc = { 1,0 };
	std::mt19937 rng;
	Fruit f;
	Obstacle obs;
	int snakeRate = 20;
	int snakeMoveCounter = 0;
	bool isOver = false;
	bool isStarted = false;
	int eatenCount = 1;
	int milestone = 0;
	/********************************/
};
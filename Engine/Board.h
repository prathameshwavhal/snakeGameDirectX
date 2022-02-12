#pragma once
//Not all pixels of the screen are available to the snake. The cells act as individual pixels
#include "Graphics.h"
#include "Loctation.h"
class Board
{
public:
	Board(Graphics& gfx);
	void DrawCell(const Location& loc, Color c);			//Drawing segments
	int gridWidth() const;									//returns width. Utility
	int gridHeight() const;									//---||--- (height)
	bool isInBoard(Location& loc) const;					//Checks if segment is in the board, returns false if not
	void DrawBorder();
private:
	static constexpr int dimension = 20;					//cell side size
	static constexpr int width = 40;						//cells in X direction
	static constexpr int height = 30;						//cells in Y direction
	Graphics& gfx;
};
#include "Board.h"
#include <assert.h>

Board::Board(Graphics& gfx)
	:
	gfx(gfx)
{
}

void Board::DrawCell(const Location& loc, Color c)
{
	assert(loc.x >= 0);
	assert(loc.x <= width);
	assert(loc.y >= 0);
	assert(loc.y <= height);
	gfx.DrawRectDim(loc.x * dimension, loc.y * dimension, dimension, dimension,c);
}

int Board::gridWidth() const
{
	return width;
}

int Board::gridHeight() const
{
	return height;
}

bool Board::isInBoard(Location& loc) const
{
	return loc.x>=0 && loc.x<width && 
		loc.y>=0 && loc.y<height;
}

void Board::DrawBorder()
{
	int i = 20, j = 20;
	for (; i < gfx.ScreenHeight - 20; i++)
	{
		gfx.PutPixel(i, j, 255, 255, 255);
		gfx.PutPixel(i, gfx.ScreenWidth - 20, 255, 255, 255);
	}
	for (; j < gfx.ScreenWidth - 20; j++)
	{
		gfx.PutPixel(i, j, 255, 255, 255);
		gfx.PutPixel(20, j, 255, 255, 255);
	}
}


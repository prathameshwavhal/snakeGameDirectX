#include "Obstacle.h"
#include "Snake.h"

Obstacle::Obstacle(std::mt19937& rng, const Board& brd, const Snake& snake)
{
	Respawn(rng, brd, snake);
}

void Obstacle::Respawn(std::mt19937& rng, const Board& brd, const Snake& snake)
{
	std::uniform_int_distribution<int> xDist(0, brd.gridWidth() - 1);
	std::uniform_int_distribution<int> yDist(0, brd.gridHeight() - 1);

	Location newLoc;
	do
	{
		newLoc.x = xDist(rng);
		newLoc.y = yDist(rng);
	} while (snake.isInTile(newLoc));

	loc = newLoc;
}
/*
bool Obstacle::crash(const Location& target) const
{
	for (int i = 0; i < size; i++)
	{
		if (Snake::GetNextHeadLocation(Snake::) == target)
		{
			return true;
		}
	}
	return false;
}*/

void Obstacle::Draw(Board& brd) const
{
	brd.DrawCell(loc, c);
}

const Location& Obstacle::GetLocation() const
{
	return loc;
}
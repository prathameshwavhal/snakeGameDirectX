#include "Goal.h"

Fruit::Fruit(std::mt19937& rng, const Board& brd, const Snake& snake)
{
	Respawn(rng, brd, snake);
}

void Fruit::Respawn(std::mt19937& rng, const Board& brd, const Snake& snake)
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

void Fruit::Draw(Board& brd) const
{
	brd.DrawCell(loc, c);
}

const Location& Fruit::GetLocation() const
{
	return loc;
}

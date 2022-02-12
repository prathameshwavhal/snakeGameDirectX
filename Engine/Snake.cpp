#include "Snake.h"
#include <assert.h>

Snake::Snake(const Location& loc)
{
	constexpr int nBodyColours = 4;
	constexpr Color BodyColours[nBodyColours] =
	{
		{55,55,55},
		{100,100,100},
		{150,150,150},
		{100,100,100}
	};
	for (int i = 0; i < MAX; i++)
	{
		segments[i].InitBody(BodyColours[i % nBodyColours]);
	}
	segments[0].InitHead(loc);
}

void Snake::MoveBy(const Location& delta_loc)
{
	for (int i = size - 1; i > 0; i--)
	{
		segments[i].Follow(segments[i - 1]);
	}
	segments[0].MoveBy(delta_loc);
}

Location Snake::GetNextHeadLocation(const Location& delta_loc) const
{
	Location l(segments[0].GetLocation());
	l.Add(delta_loc);
	return l;
}

void Snake::Grow()
{
	if (size < MAX)
	{
		size++;
	}
}

void Snake::Draw(Board& b) const
{
	for (int i = 0; i < size; i++)
	{
		segments[i].Draw(b);
	}
}

bool Snake::isInTile_end(const Location& target) const
{
	for (int i = 0; i < size-1; i++)
	{
		if (segments[i].GetLocation() == target)
		{
			return true;
		}
	}
	return false;
}

bool Snake::isInTile(const Location& target) const
{
	for (int i = 0; i < size ; i++)
	{
		if (segments[i].GetLocation() == target)
		{
			return true;
		}
	}
	return false;
}

void Snake::Segment::InitHead(const Location& loc1)
{
	loc = loc1;
	c = Snake::headColor;
}

void Snake::Segment::InitBody(Color c_in)
{
	c = c_in;
}

void Snake::Segment::Follow(const Segment& next)
{
	loc = next.loc;
}

void Snake::Segment::Draw(Board& b) const
{
	int i = 0;
	b.DrawCell(loc, c);
}

void Snake::Segment::MoveBy(const Location& delta_loc)
{
	assert(abs(delta_loc.x) + abs(delta_loc.y) == 1);
	loc.Add(delta_loc);
}

const Location Snake::Segment::GetLocation() const
{
	return loc;
}

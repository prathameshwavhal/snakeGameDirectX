#pragma once
#include "Board.h"

class Snake
{
private:
	class Segment
	{
	public:
		void InitHead(const Location& loc1);			//Specifies head color and location, board draws it
		void InitBody(Color c);							//Specifies segment color. board draws it
		void Follow(const Segment& next);				//Makes the tail follow the head
		void Draw(Board& b) const;						//Draws segment
		void MoveBy(const Location& delta_loc);			//Moves according to delta_loc. Calls Follow()
		const Location GetLocation() const;
	private:
		Location loc;
		Color c;
	};

	static constexpr Color headColor = Colors::Cyan;

	static constexpr int MAX = 100;
	Segment segments[MAX];
	int size = 1;									//actual size

public:
	Snake(const Location& loc);					//Constructor
	void MoveBy(const Location& delta_loc);		//Moves entire snake, makes it follow the head
	Location GetNextHeadLocation(const Location& delta_loc) const;
	//Location GetHeadLocation();
	void Grow();								//Increases size so that Draw() creates a segment
	void Draw(Board& b) const;					//inhibited by size. Grows in the next frame of initialisation
	bool isInTile_end(const Location& target) const;
	bool isInTile(const Location& target) const;
};
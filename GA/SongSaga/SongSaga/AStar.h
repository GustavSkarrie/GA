#ifndef ASTAR_HEADER
#define ASTAR_HEADER

#include "Path.h"
#include "Grid.h"
#include <fstream>

static class AStar
{
public:
	AStar();
	~AStar();

	static Path GetPath(sf::Vector2i aStartPosition, sf::Vector2i aEndPostion, Grid aGrid);
	static GridBlock* CheckNeighbors(sf::Vector2i aPosition, sf::Vector2i aStartPosition, sf::Vector2i aEndPosition, std::vector<sf::Vector2i> aOpen, std::vector<sf::Vector2i> aClosed);
	static GridBlock* GetShortest(sf::Vector2i aPosition, sf::Vector2i aEndPosition, std::vector<sf::Vector2i> aOpen, std::vector<sf::Vector2i> aClosed);
	static void WriteAverage();
	static void Reset();

	static void AddTime(float aTime);
	static void AddLength(float aLength);
	
private:
	static Grid myGrid;
	static float myTime;
	static float myLength;
	static float myMaxTime;
	static float myMinTime;
};



#endif // !ASTAR_HEADER

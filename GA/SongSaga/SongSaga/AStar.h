#ifndef ASTAR_HEADER
#define ASTAR_HEADER

#include "Path.h"
#include "Grid.h"

static class AStar
{
public:
	AStar();
	~AStar();

	static Path GetPath(sf::Vector2i aStartPosition, sf::Vector2i aEndPostion, Grid aGrid);
	static GridBlock* CheckNeighbors(sf::Vector2i aPosition, sf::Vector2i aEndPosition, std::vector<sf::Vector2i> aOpen, std::vector<sf::Vector2i> aClosed);
	static GridBlock* GetShortest(sf::Vector2i aPosition, sf::Vector2i aEndPosition, std::vector<sf::Vector2i> aOpen, std::vector<sf::Vector2i> aClosed);

private:
	static Grid myGrid;
};



#endif // !ASTAR_HEADER

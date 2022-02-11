#ifndef GRID_HEADER
#define GRID_HEADER

#include "GridBlock.h"

class Grid
{
public:
	Grid();
	Grid(int aHeight, int aWidth);
	~Grid();

	void ResetStart();
	void ResetEnd();
	void AStar();

	int GetHeight();
	int GetWidth();
	
	GridBlock* GetStart();
	GridBlock* GetEnd();

	GridBlock* GetGrid(int anX, int aY);
	GridBlock* GetGrid(sf::Vector2i aPosition);

private:
	sf::Vector2i mySize;
	std::vector<std::vector<GridBlock*>> myGrid;
};



#endif // !GRID_HEADER

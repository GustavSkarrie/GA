#ifndef GRID_HEADER
#define GRID_HEADER

#include "GridBlock.h"
#include <iostream>
#include <fstream>

class Grid
{
public:
	Grid();
	Grid(int aHeight, int aWidth);
	~Grid();

	void ResetStart();
	void ResetEnd();
	void ResetGrid();

	void AStar();
	void BFS();
	void Start();

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

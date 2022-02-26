#include "Grid.h"
#include "AStar.h"
#include "BFS.h"
#include "Game.h"
#include <iostream>
#include <fstream>

Grid::Grid()
{
}

Grid::Grid(int aHeight, int aWidth)
{
	mySize = sf::Vector2i(aWidth, aHeight);
	sf::Vector2f tempVector = sf::Vector2f(0, 0);

	for (size_t x = 0; x < aWidth; x++)
	{
		tempVector.y = 0;

		myGrid.push_back(std::vector<GridBlock*>());

		for (size_t y = 0; y < aHeight; y++)
		{
			myGrid[x].push_back(new GridBlock(tempVector));
			tempVector.y += 64;
		}

		tempVector.x += 64;
	}
}

Grid::~Grid()
{
}

void Grid::ResetStart()
{
	for (size_t x = 0; x < GetWidth(); x++)
	{
		for (size_t y = 0; y < GetHeight(); y++)
		{
			myGrid[x][y]->ResetStart();
		}
	}
}

void Grid::ResetEnd()
{
	for (size_t x = 0; x < GetWidth(); x++)
	{
		for (size_t y = 0; y < GetHeight(); y++)
		{
			myGrid[x][y]->ResetEnd();
		}
	}
}

void Grid::ResetGrid()
{
	for (size_t x = 0; x < GetWidth(); x++)
	{
		for (size_t y = 0; y < GetHeight(); y++)
		{
			myGrid[x][y]->Reset();
		}
	}
}

void Grid::AStar()
{
	std::ofstream tempFile;

	tempFile.open("Astar.txt", std::ios::app);

	sf::Vector2i tempStart = sf::Vector2i(GetStart()->GetPosition().x / 64, GetStart()->GetPosition().y / 64);
	sf::Vector2i tempEnd = sf::Vector2i(GetEnd()->GetPosition().x / 64, GetEnd()->GetPosition().y / 64);

	Path tempPath = AStar::GetPath(tempStart, tempEnd, *this);
	tempFile << tempPath.GetTime() << " - " << tempPath.GetLength() << "\n";
	AStar::AddLength(tempPath.GetLength());
	AStar::AddTime(tempPath.GetTime());
	tempFile.close();
}

void Grid::BFS()
{
	std::ofstream tempFile;

	tempFile.open("BFS.txt", std::ios::app);

	sf::Vector2i tempStart = sf::Vector2i(GetStart()->GetPosition().x / 64, GetStart()->GetPosition().y / 64);
	sf::Vector2i tempEnd = sf::Vector2i(GetEnd()->GetPosition().x / 64, GetEnd()->GetPosition().y / 64);

	Path tempPath = BFS::GetPath(tempStart, tempEnd, *this);
	tempFile << tempPath.GetTime() << " - " << tempPath.GetLength() << "\n";
	BFS::AddLength(tempPath.GetLength());
	BFS::AddTime(tempPath.GetTime());
	tempFile.close();
}

void Grid::Start()
{
	Game::Reset();
	AStar::Reset();
	BFS::Reset();

	for (size_t i = 0; i < 2000; i++)
	{
		if (i % 2 == 0)
			BFS();
		else
			AStar();
	}

	AStar::WriteAverage();
	BFS::WriteAverage();
}

int Grid::GetHeight()
{
	return mySize.y;
}

int Grid::GetWidth()
{
	return mySize.x;
}

GridBlock* Grid::GetStart()
{
	for (size_t x = 0; x < GetWidth(); x++)
	{
		for (size_t y = 0; y < GetHeight(); y++)
		{
			if (myGrid[x][y]->IsStart())
				return myGrid[x][y];
		}
	}
}

GridBlock* Grid::GetEnd()
{
	for (size_t x = 0; x < GetWidth(); x++)
	{
		for (size_t y = 0; y < GetHeight(); y++)
		{
			if (myGrid[x][y]->IsEnd())
				return myGrid[x][y];
		}
	}
}

GridBlock* Grid::GetGrid(int anX, int aY)
{
	return myGrid[anX][aY];
}

GridBlock* Grid::GetGrid(sf::Vector2i aPosition)
{
	return myGrid[aPosition.x][aPosition.y];
}

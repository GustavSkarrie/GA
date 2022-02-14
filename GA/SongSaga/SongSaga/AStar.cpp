#include "AStar.h"
#include "Game.h"

AStar::AStar()
{
}

AStar::~AStar()
{
}

Path AStar::GetPath(sf::Vector2i aStartPosition, sf::Vector2i aEndPosition, Grid aGrid)
{
	float tempTime = Game::GameTime();
	myGrid = aGrid;
	std::vector<sf::Vector2i> tempOpen;
	std::vector<sf::Vector2i> tempClosed;

	tempOpen.push_back(aStartPosition);

	while (tempOpen[tempOpen.size() - 1] != aEndPosition)
	{
		GridBlock* tempShortest;
		GridBlock* tempOpenBlock = aGrid.GetGrid(tempOpen[tempOpen.size() - 1]);
		tempShortest = CheckNeighbors(tempOpen[tempOpen.size() - 1], aStartPosition, aEndPosition, tempOpen, tempClosed);

		for (size_t i = 0; i < tempOpen.size(); i++)
		{
			GridBlock* tempBlock = GetShortest(tempOpen[i], aEndPosition, tempOpen, tempClosed);

			if (tempShortest == nullptr || tempBlock != nullptr && tempBlock->GetValue() < tempShortest->GetValue())
				tempShortest = tempBlock;
		}

		for (size_t i = 0; i < tempClosed.size(); i++)
		{
			GridBlock* tempBlock = GetShortest(tempClosed[i], aEndPosition, tempOpen, tempClosed);

			if (tempShortest == nullptr || tempBlock != nullptr && tempBlock->GetValue() < tempShortest->GetValue())
				tempShortest = tempBlock;
		}

		tempOpen.push_back(sf::Vector2i(tempShortest->GetPosition().x / 64, tempShortest->GetPosition().y / 64));
	}

	std::vector<sf::Vector2i> tempPath;
	tempPath.push_back(tempOpen[tempOpen.size() - 1]);

	while (tempPath[tempPath.size() - 1] != aStartPosition)
	{
		tempPath.push_back(tempPath[tempPath.size() - 1] - aGrid.GetGrid(tempPath[tempPath.size() - 1])->GetDirection());
		aGrid.GetGrid(tempPath[tempPath.size() - 1])->SetColor(sf::Color(50, 50, 255));
	}


	return Path();
}

GridBlock* AStar::CheckNeighbors(sf::Vector2i aPosition, sf::Vector2i aStartPosition, sf::Vector2i aEndPosition, std::vector<sf::Vector2i> aOpen, std::vector<sf::Vector2i> aClosed)
{
	sf::Vector2i tempPosition = sf::Vector2i(aPosition.x - 1, aPosition.y - 2);
	GridBlock* tempBlock = nullptr;

	for (size_t x = 0; x < 3; x++)
	{
		tempPosition.y = aPosition.y - 2;

		for (size_t y = 0; y < 3; y++)
		{
			tempPosition.y++;

			if (aPosition == tempPosition || tempPosition.x > myGrid.GetWidth() - 1 || tempPosition.y > myGrid.GetHeight() - 1 || tempPosition.x < 0 || tempPosition.y < 0 || !myGrid.GetGrid(tempPosition.x, tempPosition.y)->IsActive())
				continue;

			bool tempSkip = false;

			for (size_t i = 0; i < aOpen.size(); i++)
				if (aOpen[i] == tempPosition)
					tempSkip = true;

			for (size_t i = 0; i < aClosed.size(); i++)
				if (aClosed[i] == tempPosition)
					tempSkip = true;

			if (tempSkip)
				continue;

			float tempGCost = myGrid.GetGrid(aPosition)->GetGCost() + Game::Length((sf::Vector2f)tempPosition, (sf::Vector2f)aPosition);
			float tempHCost = Game::Length((sf::Vector2f)tempPosition, (sf::Vector2f)aEndPosition);

			//if (x % 2 == 0 && y % 2 == 0)
			//	tempFloat += 0.5;

			if (tempBlock == nullptr || tempBlock->GetValue() > tempGCost + tempHCost)
					tempBlock = myGrid.GetGrid(tempPosition.x, tempPosition.y);

			if (!myGrid.GetGrid(tempPosition.x, tempPosition.y)->IsSet() || myGrid.GetGrid(tempPosition.x, tempPosition.y)->GetValue() > tempGCost + tempHCost)
				myGrid.GetGrid(tempPosition.x, tempPosition.y)->SetValue(tempGCost + tempHCost, tempGCost, tempHCost, sf::Vector2i(x - 1, y - 1));

			myGrid.GetGrid(tempPosition.x, tempPosition.y)->SetColor(sf::Color(150, 150, 255, 255));
		}

		tempPosition.x++;

	}

	return tempBlock;
}

GridBlock* AStar::GetShortest(sf::Vector2i aPosition, sf::Vector2i aEndPosition, std::vector<sf::Vector2i> aOpen, std::vector<sf::Vector2i> aClosed)
{
	sf::Vector2i tempPosition = sf::Vector2i(aPosition.x - 1, aPosition.y - 2);
	GridBlock* tempBlock = nullptr;

	for (size_t x = 0; x < 3; x++)
	{
		tempPosition.y = aPosition.y - 2;

		for (size_t y = 0; y < 3; y++)
		{
			tempPosition.y++;

			if (aPosition == tempPosition || tempPosition.x > myGrid.GetWidth() - 1 || tempPosition.y > myGrid.GetHeight() - 1 || tempPosition.x < 0 || tempPosition.y < 0 || !myGrid.GetGrid(tempPosition.x, tempPosition.y)->IsActive())
				continue;

			bool tempSkip = false;

			for (size_t i = 0; i < aOpen.size(); i++)
				if (aOpen[i] == tempPosition)
					tempSkip = true;

			for (size_t i = 0; i < aClosed.size(); i++)
				if (aClosed[i] == tempPosition)
					tempSkip = true;

			if (tempSkip)
				continue;

			if (tempBlock == nullptr || tempBlock->GetValue() > myGrid.GetGrid(tempPosition.x, tempPosition.y)->GetValue())
				tempBlock = myGrid.GetGrid(tempPosition.x, tempPosition.y);

		}

		tempPosition.x++;

	}

	return tempBlock;
}

Grid AStar::myGrid;
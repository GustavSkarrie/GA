#include "Path.h"
#include "Game.h"

Path::Path()
{
}

Path::Path(float aTime, std::vector<sf::Vector2i> aPath)
{
	myTime = aTime;
	myPath = aPath;
}

Path::~Path()
{
}

float Path::GetTime()
{
	return myTime;
}

float Path::GetLength()
{
	float tempLength = 0;

	for (size_t i = 1; i < myPath.size(); i++)
	{
		tempLength += Game::Length((sf::Vector2f)myPath[i], (sf::Vector2f)myPath[i - 1]);
	}

	return tempLength;
}

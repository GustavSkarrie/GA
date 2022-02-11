#include "Path.h"

Path::Path()
{
}

Path::Path(float aTime, std::vector<sf::Vector2f> aPath)
{
	myTime = aTime;
	myPath = aPath;
}

Path::~Path()
{
}
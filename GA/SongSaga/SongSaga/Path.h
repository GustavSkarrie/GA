#ifndef PATH_HEADER
#define PATH_HEADER

#include<SFML/Graphics.hpp>

class Path
{
public:
	Path();
	Path(float aTime, std::vector<sf::Vector2i> aPath);
	~Path();

	float GetTime();
	float GetLength();

private:
	float myTime;
	std::vector<sf::Vector2i> myPath;
};



#endif // !PATH_HEADER

#ifndef PATH_HEADER
#define PATH_HEADER

#include<SFML/Graphics.hpp>

class Path
{
public:
	Path();
	Path(float aTime, std::vector<sf::Vector2f> aPath);
	~Path();

private:
	float myTime;
	std::vector<sf::Vector2f> myPath;
	float myLength;
};



#endif // !PATH_HEADER

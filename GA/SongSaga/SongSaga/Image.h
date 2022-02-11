#ifndef IMAGE_HEADER
#define IMAGE_HEADER

#include <SFML/Graphics.hpp>

#include "UIObject.h"

class Image : public UIObject
{
public:
	Image();
	Image(sf::Texture* anImage, sf::Vector2f aPosition, sf::Vector2f aSize, float anOrder);
	Image(sf::Texture* anImage, sf::Vector2f aPosition, sf::Vector2f aSize, float anOrder, sf::Color aColor);
	~Image();

	void Draw(sf::RenderWindow& aWindow);

private:

};



#endif // !IMAGE_HEADER

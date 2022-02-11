#ifndef MOVINGTEXT_HEADER
#define MOVINGTEXT_HEADER

#include "Object.h"
#include <string>

class MovingText : public Object
{
public:
	MovingText();
	MovingText(std::string aText, sf::Vector2f aStartPosition, sf::Vector2f aEndPosition, float aSpeed);
	MovingText(std::string aText, sf::Vector2f aStartPosition, sf::Vector2f aEndPosition, float aSpeed, sf::Color aColor);
	~MovingText();

	void Update();
	void Draw(sf::RenderWindow& aWindow);


private:
	sf::Vector2f myStartPosition;
	sf::Vector2f myEndPosition;
	sf::Color myColor;
	sf::String myString;
	float mySpeed;
	int myFontSize;
	sf::Font* myFont;
};

#endif // !MOVINGTEXT_HEADER

#ifndef TEXT_HEADER
#define TEXT_HEADER

#include "UIObject.h"

#include <string>

class Text : public UIObject
{
public:
	Text();
	Text(std::string someText, sf::Vector2f aPosition, sf::Vector2f aSize, float anOrder);
	Text(std::string someText, sf::Vector2f aPosition, sf::Vector2f aSize, float anOrder, int aFontSize, sf::Font* aFont);
	Text(std::string someText, sf::Vector2f aPosition, sf::Vector2f aSize, float anOrder, sf::Color aColor);
	Text(std::string someText, sf::Vector2f aPosition, sf::Vector2f aSize, float anOrder, int aFontSize, sf::Font* aFont, sf::Color aColor);
	Text(std::string someText, sf::Vector2f aPosition, sf::Vector2f aSize, float anOrder, int aFontSize, sf::Font* aFont, sf::Color aColor, sf::Text::Style aTextStyle);
	Text(std::string someText, sf::Vector2f aPosition, sf::Vector2f aSize, float anOrder, int aFontSize, sf::Font* aFont, sf::Color aColor, sf::Text::Style aTextStyle, bool aCentered);

	~Text();

	void Draw(sf::RenderWindow& aWindow);

	void SetText(std::string aText);
	void SetSize(sf::Vector2f aVector);

private:
	std::string myText;
	sf::Font* myFont;
	sf::Text::Style myStyle = sf::Text::Style::Regular;
	sf::Vector2f mySizeChange;
	int myFontSize;
	bool myCentered;
};



#endif // !TEXT_HEADER

#include "Text.h"
#include "FontManager.h"

Text::Text()
{
}

Text::Text(std::string someText, sf::Vector2f aPosition, sf::Vector2f aSize, float anOrder)
{
	myText = someText;
	myPosition = aPosition;
	mySize = aSize;
	myOrder = anOrder;
	myBlocks = false;
	myFont = FontManager::Prompt();
	myFontSize = 14;

	myColor = sf::Color(255, 255, 255, 255);
	Init();
}

Text::Text(std::string someText, sf::Vector2f aPosition, sf::Vector2f aSize, float anOrder, int aFontSize, sf::Font* aFont)
{
	myText = someText;
	myPosition = aPosition;
	mySize = aSize;
	myOrder = anOrder;
	myBlocks = false;
	myFont = aFont;
	myFontSize = aFontSize;

	myColor = sf::Color(255, 255, 255, 255);
	Init();
}

Text::Text(std::string someText, sf::Vector2f aPosition, sf::Vector2f aSize, float anOrder, sf::Color aColor)
{
	myText = someText;
	myPosition = aPosition;
	mySize = aSize;
	myOrder = anOrder;
	myColor = aColor;
	myBlocks = false;
	myFont = FontManager::Lobster();
	myFontSize = 14;

	Init();
}

Text::Text(std::string someText, sf::Vector2f aPosition, sf::Vector2f aSize, float anOrder, int aFontSize, sf::Font* aFont, sf::Color aColor)
{
	myText = someText;
	myPosition = aPosition;
	mySize = aSize;
	myOrder = anOrder;
	myColor = aColor;
	myBlocks = false;
	myFont = aFont;
	myFontSize = aFontSize;

	Init();
}

Text::Text(std::string someText, sf::Vector2f aPosition, sf::Vector2f aSize, float anOrder, int aFontSize, sf::Font* aFont, sf::Color aColor, sf::Text::Style aTextStyle)
{
	myText = someText;
	myPosition = aPosition;
	mySize = aSize;
	myOrder = anOrder;
	myColor = aColor;
	myBlocks = false;
	myFont = aFont;
	myStyle = aTextStyle;
	myFontSize = aFontSize;

	Init();
}

Text::Text(std::string someText, sf::Vector2f aPosition, sf::Vector2f aSize, float anOrder, int aFontSize, sf::Font* aFont, sf::Color aColor, sf::Text::Style aTextStyle, bool aCentered)
{
	myText = someText;
	myPosition = aPosition;
	mySize = aSize;
	myOrder = anOrder;
	myColor = aColor;
	myBlocks = false;
	myFont = aFont;
	myStyle = aTextStyle;
	myFontSize = aFontSize;
	myCentered = aCentered;

	Init();
}

Text::~Text()
{
}

void Text::Draw(sf::RenderWindow& aWindow)
{
	if (!myActive || myParentSet && !myParent->GetActive())
		return;

	sf::Text tempText;
	tempText.setFont(*myFont);
	tempText.setString(myText);
	tempText.setCharacterSize(myFontSize);
	tempText.setFillColor(myColor);
	tempText.setStyle(myStyle);

	tempText.setScale(sf::Vector2f(1, 1) + mySizeChange);

	if (mySize != sf::Vector2f(0,0))
		tempText.setScale(mySize + mySizeChange);

	if (myCentered)
	{
		sf::FloatRect tempTextRect = tempText.getLocalBounds();
		tempText.setOrigin(tempTextRect.left + tempTextRect.width / 2.0f, tempTextRect.top + tempTextRect.height / 2.0f);
	}

	if (myParentSet)
		tempText.setPosition(myPosition + myParent->GetPPosition());
	else
		tempText.setPosition(myPosition);

	aWindow.draw(tempText);
}

void Text::SetText(std::string aText)
{
	myText = aText;
}

void Text::SetSize(sf::Vector2f aVector)
{
	mySizeChange = aVector;
}

#include "MovingText.h"
#include "FontManager.h"
#include "Game.h"
#include "Camera.h"

MovingText::MovingText()
{
}

MovingText::MovingText(std::string aText, sf::Vector2f aStartPosition, sf::Vector2f aEndPosition, float aSpeed)
{
	myString = aText;
	myFontSize = 8;
	myFont = FontManager::Prompt();
	myColor = sf::Color(255, 0, 0);
	myStartPosition = aStartPosition;
	myPosition = aStartPosition;
	myEndPosition = aEndPosition;
	mySpeed = aSpeed;

	Init();
}

MovingText::MovingText(std::string aText, sf::Vector2f aStartPosition, sf::Vector2f aEndPosition, float aSpeed, sf::Color aColor)
{
	myString = aText;
	myFontSize = 8;
	myFont = FontManager::Prompt();
	myColor = aColor;
	myStartPosition = aStartPosition;
	myPosition = aStartPosition;
	myEndPosition = aEndPosition;
	mySpeed = aSpeed;

	Init();
}

MovingText::~MovingText()
{
}

void MovingText::Update()
{
	myPosition = sf::Vector2f(myPosition.x + mySpeed * (myEndPosition.x - myPosition.x), myPosition.y + mySpeed * (myEndPosition.y - myPosition.y));
	myColor = sf::Color(myColor.r, myColor.g, myColor.b, 255 * pow(fabs(Game::Length(myPosition, myEndPosition) / Game::Length(myStartPosition, myEndPosition)), 0.4f));

	if (Game::Length(myPosition, myEndPosition) <= mySpeed)
	{
 		Remove();
		return;
	}
}

void MovingText::Draw(sf::RenderWindow& aWindow)
{
	sf::Text tempText;
	tempText.setFont(*myFont);
	tempText.setString(myString);
	tempText.setCharacterSize(myFontSize);
	tempText.setFillColor(myColor);

	tempText.setPosition(myPosition + Camera::GetVector());

	aWindow.draw(tempText);
}

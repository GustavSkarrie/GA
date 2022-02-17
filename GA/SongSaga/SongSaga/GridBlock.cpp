#include "GridBlock.h"
#include "TextureManager.h"
#include "MouseManager.h"
#include "Game.h"
#include "Camera.h"
#include "FontManager.h"

GridBlock::GridBlock()
{
}

GridBlock::GridBlock(sf::Vector2f aPosition)
{
	myPosition = aPosition;
	mySize = sf::Vector2f(64, 64);
	mySprite.setTexture(*TextureManager::EmptyBox());
	mySprite.setColor(sf::Color(255, 255, 255, 255));

	Init();
}

GridBlock::~GridBlock()
{
}

void GridBlock::Update()
{
	if (Game::GetMode() != EditorMode::None && MouseManager::IsInside(myPosition, mySize) && MouseManager::LMouseClick())
	{
		switch (Game::GetMode())
		{
		case Wall:
			if (myActive) 
			{
				mySprite.setColor(sf::Color(80, 80, 80, 255));
				myStartpoint = false;
				myEndpoint = false;
			}
			else
				mySprite.setColor(sf::Color(255, 255, 255, 255));

			myActive = !myActive;
			break;

		case StartPoint:
			if (!myStartpoint) 
			{
				mySprite.setColor(sf::Color(100, 255, 100, 255));
				myActive = true;
				myEndpoint = false;
			}
			else
				mySprite.setColor(sf::Color(255, 255, 255, 255));

			Game::GetGrid().ResetStart();
			myStartpoint = !myStartpoint;
			break;

		case Endpoint:
			if (!myEndpoint) 
			{
				mySprite.setColor(sf::Color(255, 100, 100, 255));
				myActive = true;
				myStartpoint = false;
			}
			else
				mySprite.setColor(sf::Color(255, 255, 255, 255));

			Game::GetGrid().ResetEnd();
			myEndpoint = !myEndpoint;
			break;
		}
	}
}

void GridBlock::Draw(sf::RenderWindow& aWindow)
{
	sf::Vector2f tempScale;
	tempScale.x = mySize.x / mySprite.getTextureRect().width;
	tempScale.y = mySize.y / mySprite.getTextureRect().height;

	mySprite.setScale(tempScale);
	mySprite.setPosition(myPosition + Camera::GetVector());

	aWindow.draw(mySprite);

	if (myUI && myValueSet) 
	{
		sf::Text tempText;
		tempText.setFont(*FontManager::Prompt());
		tempText.setString(std::to_string((int)round(10 * myValue)));
		tempText.setCharacterSize(16);
		tempText.setFillColor(sf::Color::Black);

		tempText.setScale(sf::Vector2f(1, 1));
		sf::FloatRect tempTextRect = tempText.getLocalBounds();
		tempText.setOrigin(tempTextRect.left + tempTextRect.width / 2.0f, tempTextRect.top + tempTextRect.height / 2.0f);
		tempText.setPosition(myPosition + Camera::GetVector() + sf::Vector2f(32,32));

		aWindow.draw(tempText);
	}
}

void GridBlock::ResetEnd()
{
	if (myEndpoint)
		mySprite.setColor(sf::Color(255, 255, 255, 255));

	myEndpoint = false;
}

void GridBlock::ResetStart()
{
	if (myStartpoint)
		mySprite.setColor(sf::Color(255, 255, 255, 255));

	myStartpoint = false;
}

void GridBlock::Reset()
{
	if (myActive && !myEndpoint && !myStartpoint)
		mySprite.setColor(sf::Color(255, 255, 255, 255));

	myValueSet = false;
	myValue = 0;
	myDirection = sf::Vector2i(0, 0);
}

void GridBlock::SetColor(sf::Color aColor)
{
	if (!myEndpoint && !myStartpoint)
		mySprite.setColor(aColor);
}

void GridBlock::SetValue(float aValue, float aGCost, float aHCost, sf::Vector2i aDirection)
{
	myValue = aValue;
	myGCost = aGCost;
	myHCost = aHCost;
	myDirection = aDirection;
	myValueSet = true;
}

float GridBlock::GetValue()
{
	return myValue;
}

float GridBlock::GetGCost()
{
	return myGCost;
}

sf::Vector2i GridBlock::GetDirection()
{
	return myDirection;
}

bool GridBlock::IsSet()
{
	return myValueSet;
}

bool GridBlock::IsActive()
{
	return myActive;
}

bool GridBlock::IsEnd()
{
	return myEndpoint;
}

bool GridBlock::IsStart()
{
	return myStartpoint;
}

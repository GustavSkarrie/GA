#include "GridBlock.h"
#include "TextureManager.h"
#include "MouseManager.h"
#include "Game.h"

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

void GridBlock::SetColor(sf::Color aColor)
{
	mySprite.setColor(aColor);
}

void GridBlock::SetValue(float aValue)
{
	myValue = aValue;
}

float GridBlock::GetValue()
{
	return myValue;
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

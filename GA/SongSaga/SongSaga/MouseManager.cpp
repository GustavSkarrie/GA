#include "MouseManager.h"
#include "UIManager.h"
#include "Game.h"
#include "Camera.h"

MouseManager::MouseManager()
{
}

MouseManager::~MouseManager()
{
}

void MouseManager::Update(sf::RenderWindow& aWindow, sf::View& aView)
{
	myPosition.x = sf::Mouse::getPosition(aWindow).x;
	myPosition.y = sf::Mouse::getPosition(aWindow).y;
}

void MouseManager::LateUpdate()
{
	if (!LMouseDown())
		myLMouseFrame = false;

	if (!RMouseDown())
		myRMouseFrame = false;

	myLMouseDown = myLMouseFrame;
	myRMouseDown = myRMouseFrame;
}

bool MouseManager::IsInside(sf::Vector2f aPosition, sf::Vector2f aSize)
{
	if (MouseManager::GetViewPosition().x > aPosition.x && MouseManager::GetViewPosition().y > aPosition.y && MouseManager::GetViewPosition().x < aPosition.x + aSize.x && MouseManager::GetViewPosition().y < aPosition.y + aSize.y)
		return true;

	return false;
}

bool MouseManager::LMouseDown()
{
	bool tempBool = sf::Mouse::isButtonPressed(sf::Mouse::Left);

	if (tempBool)
		myLMouseFrame = true;

	return tempBool;
}

bool MouseManager::LMouseClick()
{
	if (!myLMouseDown)
		return LMouseDown();

	return false;
}

bool MouseManager::RMouseDown()
{
	bool tempBool = sf::Mouse::isButtonPressed(sf::Mouse::Right);

	if (tempBool)
		myRMouseFrame = true;

	return tempBool;
}

bool MouseManager::RMouseClick()
{
	if (!myRMouseDown)
		return RMouseDown();

	return false;
}

bool MouseManager::OverUI()
{
	return UIManager::MouseOver();
}

sf::Vector2f MouseManager::GetPosition()
{
	return myPosition;
}

sf::Vector2f MouseManager::GetViewPosition()
{
	return Game::GetWindow()->mapPixelToCoords(sf::Vector2i(myPosition.x, myPosition.y)) - Camera::GetVector();
}

sf::Vector2f MouseManager::myPosition;
bool MouseManager::myLMouseDown = false;
bool MouseManager::myLMouseFrame = false;
bool MouseManager::myRMouseDown = false;
bool MouseManager::myRMouseFrame = false;
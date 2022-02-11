#include "UIObject.h"
#include "UIManager.h"

UIObject::UIObject()
{
}

UIObject::~UIObject()
{
}

void UIObject::Init()
{
	UIManager::AddObject(*this);
	myID = UIManager::GetId();
	UIManager::NextId();
}

void UIObject::Reset()
{
}

void UIObject::Remove()
{
	UIManager::RemoveObject(*this);
	delete(this);
}

void UIObject::Draw(sf::RenderWindow& aWindow)
{
}

void UIObject::Update()
{
}

bool UIObject::MouseOver()
{
	return UIManager::MouseOver(*this);
}

void UIObject::SetPosition(sf::Vector2f aPosition)
{
	myPosition = aPosition;
}

sf::Vector2f UIObject::GetPosition()
{
	return myPosition;
}

sf::Vector2f UIObject::GetPPosition()
{
	if (myParentSet)
		return myPosition + myParent->GetPPosition();
	else
		return myPosition;
}

void UIObject::SetSize(sf::Vector2f aSize)
{
	mySize = aSize;
}

sf::Vector2f UIObject::GetSize()
{
	return mySize;
}

void UIObject::SetColor(sf::Color aColor)
{
	myColor = aColor;
}

sf::Color UIObject::GetColor()
{
	return myColor;
}

void UIObject::SetOrder(float anOrder)
{
	myOrder = anOrder;
}

float UIObject::GetOrder()
{
	if (myParentOrder)
		return myParent->GetOrder() + myOrder;

	return myOrder;
}

void UIObject::SetParent(UIObject& aParent)
{
	myParent = &aParent;
	myParentSet = true;
	myRenderInWorld = myParent->RenderInWorld();
}

bool UIObject::IsButton()
{
	return myIsButton;
}

void UIObject::SetRenderInWorld(bool aBool)
{
	myRenderInWorld = aBool;
}

bool UIObject::RenderInWorld()
{
	return myRenderInWorld;
}

void UIObject::SetActive(bool aBool)
{
	myActive = aBool;
}

bool UIObject::GetActive()
{
	if (myActive && myParentSet)
		return myParent->GetActive();

	return myActive;
}

void UIObject::SetParentOrder(bool aBool)
{
	myParentOrder = aBool;
}

void UIObject::SetBlocks(bool aBool)
{
	myBlocks = aBool;
}

bool UIObject::BlocksUI()
{
	return myBlocks;
}

int UIObject::GetId()
{
	return myID;
}

#include "Canvas.h"
#include "UIObject.h"

#include "Game.h"
#include "UIManager.h"

#include <SFML/Graphics.hpp>

Canvas::Canvas()
{
	Init();
}

Canvas::Canvas(sf::Vector2f aPosition, sf::Vector2f aSize, int anOrder)
{
	myPosition = aPosition;
	mySize = aSize;
	myOrder = anOrder;
	myBlocks = false;

	myColor = sf::Color(0, 0, 0, 0);
	Init();
}

Canvas::Canvas(sf::Vector2f aPosition, sf::Vector2f aSize, sf::Color aColor, int anOrder)
{
	myPosition = aPosition;
	mySize = aSize;
	myColor = aColor;
	myOrder = anOrder;
	myBlocks = true;

	Init();
}

Canvas::~Canvas()
{
}

void Canvas::ResetButtons()
{
	for (size_t i = 0; i < myChildren.size(); i++)
	{
		if (myChildren[i]->IsButton())
			myChildren[i]->Reset();
	}
}

std::vector<UIObject*> Canvas::GetChildren()
{
	return myChildren;
}

void Canvas::SetChildrenBlocks(bool aBool)
{
	for (size_t i = 0; i < myChildren.size(); i++)
	{
		myChildren[i]->SetBlocks(aBool);
	}
}

void Canvas::SetChildrenOrders(bool aBool)
{
	for (size_t i = 0; i < myChildren.size(); i++)
	{
		myChildren[i]->SetParentOrder(aBool);
	}
}

void Canvas::Remove()
{
	for (size_t i = 0; i < myChildren.size(); i++)
	{
		myChildren[i]->Remove();
	}

	myChildren.clear();
	UIManager::RemoveObject(*this);
	delete(this);
}

void Canvas::Draw(sf::RenderWindow& aWindow)
{
	if (!myActive || myParentSet && !myParent->GetActive())
		return;

	if (myColor.a == 0)
		myBlocks = false;

	sf::RectangleShape tempShape(mySize);
	tempShape.setFillColor(myColor);

	if (myParentSet) 
		tempShape.setPosition(myPosition + myParent->GetPPosition());
	else
		tempShape.setPosition(myPosition);

	aWindow.draw(tempShape);
}

void Canvas::AddObject(UIObject* anObject)
{
	anObject->SetParent(*this);
	myChildren.push_back(anObject);
}

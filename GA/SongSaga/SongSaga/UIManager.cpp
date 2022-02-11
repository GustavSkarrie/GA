#include "UIManager.h"
#include "MouseManager.h"

#include <vector>

UIManager::UIManager()
{
}

UIManager::~UIManager()
{
}

void UIManager::Update()
{
	for (size_t i = 0; i < myObjects.size(); i++)
	{
		myObjects[i]->Update();
	}
}

void UIManager::Draw(sf::RenderWindow& aWindow)
{
	SortList();

	for (size_t i = 0; i < myObjects.size(); i++)
	{
		if (!myObjects[i]->RenderInWorld())
			myObjects[i]->Draw(aWindow);
	}
}

void UIManager::DrawWorld(sf::RenderWindow& aWindow)
{
	SortList();

	for (size_t i = 0; i < myObjects.size(); i++)
	{
		if (myObjects[i]->RenderInWorld())
			myObjects[i]->Draw(aWindow);
	}
}

void UIManager::AddObject(UIObject& anObject)
{
	myObjects.push_back(&anObject);
}

void UIManager::RemoveObject(UIObject& anObject)
{
	for (size_t i = 0; i < myObjects.size(); i++)
		if (myObjects[i]->GetId() == anObject.GetId())
			myObjects.erase(myObjects.begin() + i);
}

void UIManager::RemoveObject(int anId)
{
	for (size_t i = 0; i < myObjects.size(); i++)
		if (myObjects[i]->GetId() == anId)
			myObjects.erase(myObjects.begin() + i);
}

std::vector<UIObject*> UIManager::myObjects;
int UIManager::myCurId = 0;

bool UIManager::MouseOver(UIObject& anObject)
{
	SortList();

	for (size_t i = 0; i < myObjects.size(); i++)
	{
		UIObject* tempObject = myObjects[myObjects.size() - i - 1];

		if (tempObject->BlocksUI() && tempObject->GetActive() && !tempObject->RenderInWorld() && MouseManager::GetPosition().x > tempObject->GetPPosition().x && MouseManager::GetPosition().y > tempObject->GetPPosition().y && MouseManager::GetPosition().x < tempObject->GetPPosition().x + tempObject->GetSize().x && MouseManager::GetPosition().y < tempObject->GetPPosition().y + tempObject->GetSize().y)
		{
			if (tempObject->GetId() == anObject.GetId())
				return true;
			else
				return false;
		}
	}

	return false;
}

bool UIManager::MouseOver()
{
	for (size_t i = 0; i < myObjects.size(); i++)
	{
		UIObject* tempObject = myObjects[myObjects.size() - i - 1];

		if (tempObject->BlocksUI() && MouseManager::GetPosition().x > tempObject->GetPPosition().x && MouseManager::GetPosition().y > tempObject->GetPPosition().y && MouseManager::GetPosition().x < tempObject->GetPPosition().x + tempObject->GetSize().x && MouseManager::GetPosition().y < tempObject->GetPPosition().y + tempObject->GetSize().y)
		{
			return true;
		}
	}

	return false;
}

void UIManager::SortList()
{
	std::vector<UIObject*> tempList;

	for (size_t i = 0; i < myObjects.size(); i++)
		tempList.push_back(myObjects[i]);

	myObjects.clear();

	for (size_t i = 0; i < tempList.size(); i++)
	{
		int tempPos = 0;
		UIObject* tempObject;
		tempObject = tempList[0];

		for (size_t y = 0; y < tempList.size(); y++)
		{
			if (tempObject->GetOrder() > tempList[y]->GetOrder()) 
			{
				tempObject = tempList[y];
				tempPos = y;
			}
		}

		myObjects.push_back(tempObject);
		tempList.erase(tempList.begin() + tempPos);
		i--;
	}
}

void UIManager::NextId()
{
	myCurId++;
}

int UIManager::GetId()
{
	return myCurId;
}

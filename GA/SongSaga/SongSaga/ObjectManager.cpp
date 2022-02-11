#include "ObjectManager.h"

#include <vector>

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
}

void ObjectManager::Update()
{
	for (size_t i = 0; i < myObjects.size(); i++)
	{
		myObjects[i]->Update();
	}
}

void ObjectManager::Draw(sf::RenderWindow& aWindow)
{
	SortList();

	for (size_t i = 0; i < myObjects.size(); i++)
	{
		myObjects[i]->Draw(aWindow);
	}
}

void ObjectManager::AddObject(Object& anObject)
{
	myObjects.push_back(&anObject);
}

void ObjectManager::RemoveObject(Object& anObject)
{
	for (size_t i = 0; i < myObjects.size(); i++)
		if (myObjects[i]->GetId() == anObject.GetId())
			myObjects.erase(myObjects.begin() + i);
}

void ObjectManager::RemoveObject(int anId)
{
	for (size_t i = 0; i < myObjects.size(); i++)
		if (myObjects[i]->GetId() == anId)
			myObjects.erase(myObjects.begin() + i);
}

void ObjectManager::SortList()
{
	std::vector<Object*> tempList;

	for (size_t i = 0; i < myObjects.size(); i++)
		tempList.push_back(myObjects[i]);

	myObjects.clear();

	for (size_t i = 0; i < tempList.size(); i++)
	{
		int tempPos = 0;
		Object* tempObject;
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

std::vector<Object*> ObjectManager::myObjects;
int ObjectManager::myCurId = 0;

void ObjectManager::NextId()
{
	myCurId++;
}

int ObjectManager::GetId()
{
	return myCurId;
}

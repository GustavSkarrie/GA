#ifndef OBJECTMANAGER_HEADER
#define OBJECTMANAGER_HEADER

#include "Object.h"

#include <vector>

static class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();

	static void Update();
	static void Draw(sf::RenderWindow& aWindow);

	static void AddObject(Object& anObject);
	static void RemoveObject(Object& anObject);
	static void RemoveObject(int anId);
	static void SortList();

	static void NextId();
	static int GetId();

private:
	static std::vector<Object*> myObjects;
	static int myCurId;
};


#endif // !OBJECTMANAGER_HEADER


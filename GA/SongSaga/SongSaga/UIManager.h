#ifndef UIMANAGER_HEADER
#define UIMANAGER_HEADER

#include "UIObject.h"

#include <vector>

class UIManager
{
public:
	UIManager();
	~UIManager();

	static void Update();
	static void Draw(sf::RenderWindow& aWindow);
	static void DrawWorld(sf::RenderWindow& aWindow);

	static void AddObject(UIObject& anObject);
	static void RemoveObject(UIObject& anObject);
	static void RemoveObject(int anId);

	static bool MouseOver(UIObject& anObject);
	static bool MouseOver();
	static void SortList();
	static void NextId();
	static int GetId();

private:
	static std::vector<UIObject*> myObjects;
	static int myCurId;
};

#endif // !UIMANAGER_HEADER



#ifndef MOUSE_MANAGER
#define MOUSE_MANAGER

#include <SFML/Graphics.hpp>

static class MouseManager
{
public:
	MouseManager();
	~MouseManager();

	static void Update(sf::RenderWindow& aWindow, sf::View& aView);
	static void LateUpdate();
	static bool IsInside(sf::Vector2f aPosition, sf::Vector2f aSize);
	static bool LMouseDown();
	static bool LMouseClick();
	static bool RMouseDown();
	static bool RMouseClick();
	static bool OverUI();

	static sf::Vector2f GetPosition();
	static sf::Vector2f GetViewPosition();

private:
	static sf::Vector2f myPosition;
	static bool myLMouseDown;
	static bool myLMouseFrame;
	static bool myRMouseDown;
	static bool myRMouseFrame;

};


#endif // !MOUSE_MANAGER

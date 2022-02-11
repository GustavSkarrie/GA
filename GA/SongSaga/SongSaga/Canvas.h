#ifndef CANVAS_HEADER
#define CANVAS_HEADER

#include <SFML/Graphics.hpp>
#include <vector>

#include "UIObject.h"

class Canvas : public UIObject
{
public:
	Canvas();
	Canvas(sf::Vector2f aPosition, sf::Vector2f aSize, int anOrder);
	Canvas(sf::Vector2f aPosition, sf::Vector2f aSize, sf::Color aColor, int anOrder);
	~Canvas();

	void ResetButtons();
	std::vector<UIObject*> GetChildren();
	void SetChildrenBlocks(bool aBool);
	void SetChildrenOrders(bool aBool);
	void Remove();
	void Draw(sf::RenderWindow& aWindow);

	void AddObject(UIObject* anObject);

private:
	std::vector<UIObject*> myChildren;
};

#endif // !CANVAS_HEADER

#ifndef UIOBJECT_HEADER
#define UIOBJECT_HEADER

#include <SFML/Graphics.hpp>
#include <vector>

class UIObject
{
public:
	UIObject();
	~UIObject();

	void Init();
	virtual void Reset();
	virtual void Remove();
	virtual void Draw(sf::RenderWindow& aWindow);
	virtual void Update();

	bool MouseOver();

	void SetPosition(sf::Vector2f aPosition);
	sf::Vector2f GetPosition();
	sf::Vector2f GetPPosition();

	void SetSize(sf::Vector2f aSize);
	sf::Vector2f GetSize();

	void SetColor(sf::Color aColor);
	sf::Color GetColor();

	void SetOrder(float anOrder);
	float GetOrder();

	void SetParent(UIObject& aParent);
	bool IsButton();

	void SetRenderInWorld(bool aBool);
	bool RenderInWorld();

	void SetActive(bool aBool);
	bool GetActive();
	
	void SetParentOrder(bool aBool);
	void SetBlocks(bool aBool);
	bool BlocksUI();
	int GetId();

protected:
	sf::Vector2f myPosition;
	sf::Vector2f mySize;
	sf::Color myColor;
	sf::Sprite myImage;
	UIObject* myParent;
	float myOrder;
	int myID;
	bool myBlocks;
	bool myParentOrder = false;
	bool myParentSet;
	bool myIsButton;
	bool myRenderInWorld;
	bool myActive = true;
};


#endif // !UIOBJECT_HEADER

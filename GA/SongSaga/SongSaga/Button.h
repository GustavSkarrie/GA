#ifndef BUTTON_HEADER
#define BUTTON_HEADER

#include "UIObject.h"
#include "Text.h"

#include <functional>
#include <string>

class Button : public UIObject
{
public:
	Button();
	Button(std::function<void()> anEvent, std::string someText, sf::Vector2f aPosition, sf::Vector2f aSize, float anOrder);
	Button(std::function<void()> anEvent, std::string someText, sf::Vector2f aPosition, sf::Vector2f aSize, float anOrder, sf::Texture* aTexture);
	Button(std::function<void()> anEvent, std::string someText, sf::Vector2f aPosition, sf::Vector2f aSize, float anOrder, sf::Texture* aTexture, bool aToggle);
	Button(std::function<void()> anEvent, std::string someText, sf::Vector2f aPosition, sf::Vector2f aSize, float anOrder, sf::Texture* aTexture, bool aToggle, UIObject* aHoverBox);

	~Button();

	void Reset();
	void Remove();
	void Update();
	void Draw(sf::RenderWindow& aWindow);


private:
	std::function<void()> myEvent;
	Text* myText;
	float myTimePressed;
	sf::Vector2f mySizeChange;
	sf::Vector2f myCurSize;
	UIObject* myHoverBox;
	bool mySelected;
	bool myToggle;
};


#endif // !BUTTON_HEADER

#include "Button.h"
#include "MouseManager.h"
#include "UIManager.h"
#include "Game.h"
#include "TextureManager.h"
#include "FontManager.h"

#include <cmath>
#include <math.h>

Button::Button()
{
}

Button::Button(std::function<void()> anEvent, std::string someText, sf::Vector2f aPosition, sf::Vector2f aSize, float anOrder)
{
	myEvent = anEvent;
	myPosition = aPosition;
	mySize = aSize;
	myOrder = anOrder;
	myBlocks = true;
	myText = new Text(someText, sf::Vector2f(5, 5), sf::Vector2f(0, 0), anOrder + 0.01f, sf::Color(200, 200, 200, 255));
	myText->SetParent(*this);

	myCurSize = mySize;
	myImage.setTexture(*TextureManager::EmptyBox());
	myColor = sf::Color(255, 255, 255, 255);
	myIsButton = true;
	Init();
}

Button::Button(std::function<void()> anEvent, std::string someText, sf::Vector2f aPosition, sf::Vector2f aSize, float anOrder, sf::Texture* aTexture)
{
	myEvent = anEvent;
	myPosition = aPosition;
	mySize = aSize;
	myOrder = anOrder;
	myBlocks = true;
	myText = new Text(someText, sf::Vector2f(5, 7), sf::Vector2f(0, 0), anOrder + 0.01f, sf::Color(255, 255, 255, 255));
	myText->SetParent(*this);

	mySizeChange = sf::Vector2f(20, 0);
	myCurSize = mySize;
	myImage.setTexture(*aTexture);
	myColor = sf::Color(255, 255, 255, 255);
	myIsButton = true;
	Init();
}

Button::Button(std::function<void()> anEvent, std::string someText, sf::Vector2f aPosition, sf::Vector2f aSize, float anOrder, sf::Texture* aTexture, bool aToggle)
{
	myEvent = anEvent;
	myPosition = aPosition;
	mySize = aSize;
	myOrder = anOrder;
	myBlocks = true;
	myText = new Text(someText, sf::Vector2f(5, 7), sf::Vector2f(0,0), anOrder + 0.01f, 14, FontManager::RobotoMono(), sf::Color(80, 80, 80, 255), sf::Text::Bold);
	myText->SetParent(*this);
	myToggle = aToggle;

	mySizeChange = sf::Vector2f(20, 0);
	myCurSize = mySize;
	myImage.setTexture(*aTexture);
	myColor = sf::Color(255, 255, 255, 255);
	myIsButton = true;
	Init();
}

Button::Button(std::function<void()> anEvent, std::string someText, sf::Vector2f aPosition, sf::Vector2f aSize, float anOrder, sf::Texture* aTexture, bool aToggle, UIObject* aHoverBox)
{
	myEvent = anEvent;
	myPosition = aPosition;
	mySize = aSize;
	myOrder = anOrder;
	myBlocks = true;
	myText = new Text(someText, sf::Vector2f(5, 7), sf::Vector2f(0, 0), anOrder + 0.01f, 14, FontManager::RobotoMono(), sf::Color(80, 80, 80, 255), sf::Text::Bold);
	myText->SetParent(*this);
	myToggle = aToggle;
	myHoverBox = aHoverBox;

	mySizeChange = sf::Vector2f(20, 0);
	myCurSize = mySize;
	myImage.setTexture(*aTexture);
	myColor = sf::Color(255, 255, 255, 255);
	myIsButton = true;
	Init();
}

Button::~Button()
{
}

void Button::Reset()
{
	mySelected = false;
}

void Button::Remove()
{
	myText->Remove();
	UIManager::RemoveObject(*this);
	delete(this);
}

void Button::Update()
{
	if (!myActive || myParentSet && !myParent->GetActive())
		return;

	myText->SetSize(sf::Vector2f((myCurSize.x - mySize.x) / myImage.getTextureRect().width / 2, (myCurSize.y - mySize.y) / myImage.getTextureRect().height / 2));

	if (MouseOver()) 
	{
		if (myHoverBox != nullptr) 
		{
			myHoverBox->SetActive(true);
			myHoverBox->SetPosition(MouseManager::GetPosition());
		}

		if (MouseManager::LMouseDown()) 
		{
			myTimePressed = Game::GameTime();
			myEvent();

			if (myToggle)
				mySelected = true;
		}
	}
	else
	{
		if (myHoverBox != nullptr)
			myHoverBox->SetActive(false);
	}
}

void Button::Draw(sf::RenderWindow& aWindow)
{
	if (!myActive || myParentSet && !myParent->GetActive())
		return;

	sf::Vector2f tempScale;

	if (MouseOver() || mySelected)
		myCurSize = sf::Vector2f(myCurSize.x + 0.6f * (mySizeChange.x + mySize.x - myCurSize.x), myCurSize.y + 0.6f * (mySizeChange.y + mySize.y - myCurSize.y));
	else
		myCurSize = sf::Vector2f(myCurSize.x + 0.6f * (mySize.x - myCurSize.x), myCurSize.y + 0.6f * (mySize.y - myCurSize.y));


	tempScale.x = myCurSize.x / myImage.getTextureRect().width;
	tempScale.y = myCurSize.y / myImage.getTextureRect().height;

	myImage.setScale(tempScale);

	sf::Color tempColor = myColor;

	if (MouseOver() || mySelected)
		tempColor = sf::Color(myColor.r * 0.9f, myColor.g * 0.9f, myColor.b * 0.9f, 255);

	if (myTimePressed + 0.06f > Game::GameTime())
		tempColor = sf::Color(myColor.r * 0.8f, myColor.g * 0.8f, myColor.b * 0.8f, 255);

	myImage.setColor(tempColor);

	if (myParentSet)
		myImage.setPosition(myPosition + myParent->GetPPosition());
	else
		myImage.setPosition(myPosition);

	aWindow.draw(myImage);
}

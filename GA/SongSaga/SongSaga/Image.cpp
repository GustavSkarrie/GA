#include "Image.h"
#include "UIObject.h"

Image::Image()
{
}

Image::Image(sf::Texture* anImage, sf::Vector2f aPosition, sf::Vector2f aSize, float anOrder)
{
	myImage.setTexture(*anImage);
	myPosition = aPosition;
	mySize = aSize;
	myOrder = anOrder;
	myBlocks = true;

	myColor = sf::Color(255, 255, 255, 255);
	Init();
}

Image::Image(sf::Texture* anImage, sf::Vector2f aPosition, sf::Vector2f aSize, float anOrder, sf::Color aColor)
{
	myImage.setTexture(*anImage);
	myPosition = aPosition;
	mySize = aSize;
	myOrder = anOrder;
	myColor = aColor;
	myBlocks = true;
	Init();
}

Image::~Image()
{
}

void Image::Draw(sf::RenderWindow& aWindow)
{
	if (!myActive || myParentSet && !myParent->GetActive())
		return;

	sf::Vector2f tempScale;
	tempScale.x = mySize.x / myImage.getTextureRect().width;
	tempScale.y = mySize.y / myImage.getTextureRect().height;

	myImage.setScale(tempScale);
	myImage.setColor(myColor);

	if (myParentSet)
		myImage.setPosition(myPosition + myParent->GetPPosition());
	else
		myImage.setPosition(myPosition);

	aWindow.draw(myImage);
}

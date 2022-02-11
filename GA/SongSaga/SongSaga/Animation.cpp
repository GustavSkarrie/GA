#include "Animation.h"
#include "Camera.h"

Animation::Animation()
{
}

Animation::Animation(sf::Vector2f aPosition, sf::Vector2f aSize, TextureSequence aSequence, sf::Color aColor, float aSpeed, float anOrder)
{
	myPosition = aPosition;
	mySize = aSize;
	myAnimation = AnimationClip(aSequence, aSpeed);
	myColor = aColor;
	myOrder = anOrder;

	Init();
}

Animation::Animation(sf::Vector2f aPosition, sf::Vector2f aSize, sf::Vector2f anOrgin, float aRotation, TextureSequence aSequence, sf::Color aColor, float aSpeed, float anOrder)
{
	myPosition = aPosition;
	mySize = aSize;
	myRotation = aRotation;
	myOrgin = anOrgin;
	myAnimation = AnimationClip(aSequence, aSpeed);
	myColor = aColor;
	myOrder = anOrder;

	Init();
}

Animation::~Animation()
{
}

void Animation::Update()
{
	if (myAnimation.GetFrame() == myAnimation.GetMax() - 1)
		Remove();

	myAnimation.Update();

}

void Animation::Draw(sf::RenderWindow& aWindow)
{
	mySprite.setTexture(*myAnimation.GetTexture());

	sf::Vector2f tempScale;
	tempScale.x = mySize.x / mySprite.getTextureRect().width;
	tempScale.y = mySize.y / mySprite.getTextureRect().height;

	mySprite.setScale(tempScale);
	mySprite.setPosition(myPosition + Camera::GetVector());

	mySprite.setOrigin(myOrgin);
	mySprite.setRotation(myRotation);
	mySprite.setColor(myColor);
	aWindow.draw(mySprite);
}

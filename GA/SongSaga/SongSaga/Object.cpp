#include "Object.h"
#include "ObjectManager.h"
#include "Camera.h"

#include <SFML/Graphics.hpp>

Object::Object()
{
}

Object::Object(sf::Vector2f aPosition, int aDepth)
{
	myPosition = aPosition;
	myDepth = aDepth;

	Init();
}

Object::Object(sf::Vector2f aPosition, int aDepth, sf::Sprite aSprite)
{
	myPosition = aPosition;
	myDepth = aDepth;
	mySprite = aSprite;

	Init();
}

Object::~Object()
{
}

void Object::Init()
{
	ObjectManager::AddObject(*this);
	myId = ObjectManager::GetId();
	ObjectManager::NextId();
}

void Object::Remove()
{
	ObjectManager::RemoveObject(*this);
	delete(this);
}

void Object::Update()
{
}

void Object::Draw(sf::RenderWindow& aWindow)
{
	sf::Vector2f tempScale;
	tempScale.x = mySize.x / mySprite.getTextureRect().width;
	tempScale.y = mySize.y / mySprite.getTextureRect().height;

	mySprite.setScale(tempScale);
	mySprite.setPosition(myPosition + Camera::GetVector());

	aWindow.draw(mySprite);
}

sf::Sprite Object::GetSprite()
{
	return mySprite;
}

void Object::SetSprite(sf::Sprite aSprite)
{
	mySprite = aSprite;
}

sf::Vector2f Object::GetPosition()
{
	return myPosition;
}

void Object::SetPosition(sf::Vector2f aVector)
{
	myPosition = aVector;
}

void Object::SetPosition(float anX, float anY)
{
	myPosition = { anX, anY };
}

sf::Vector2f Object::GetSize()
{
	return mySize;
}

void Object::SetSize(sf::Vector2f aSize)
{
	mySize = aSize;
}

void Object::SetSize(float anX, float anY)
{
	mySize = { anX, anY };
}

float Object::GetDepth()
{
	return myDepth;
}

float Object::GetOrder()
{
	return myOrder;
}

void Object::SetDepth(float aDepth)
{
	myDepth = aDepth;
}

int Object::GetId()
{
	return myId;
}

#include "Camera.h"
#include "Game.h"

#include <SFML/Graphics.hpp>

Camera::Camera()
{
}

Camera::~Camera()
{
}

void Camera::Update(sf::RenderWindow& aWindow)
{
	sf::Keyboard tempKeyboard;

	if (tempKeyboard.isKeyPressed(tempKeyboard.W))
		myPosition.y = Game::Clamp(myPosition.y - /*Game::GetZoom() **/ mySpeed, Game::GetGrid().GetHeight() * 64, 0);

	if (tempKeyboard.isKeyPressed(tempKeyboard.S))
		myPosition.y = Game::Clamp(myPosition.y + /*Game::GetZoom() **/ mySpeed, Game::GetGrid().GetHeight() * 64, 0);

	if (tempKeyboard.isKeyPressed(tempKeyboard.D))
		myPosition.x = Game::Clamp(myPosition.x + /*Game::GetZoom() **/ mySpeed, Game::GetGrid().GetWidth() * 64, 0);

	if (tempKeyboard.isKeyPressed(tempKeyboard.A))
		myPosition.x = Game::Clamp(myPosition.x - /*Game::GetZoom() **/ mySpeed, Game::GetGrid().GetWidth() * 64, 0);
}

sf::Vector2f Camera::GetVector()
{
	return -myPosition + sf::Vector2f(Game::GetWindow()->getSize().x / 2, Game::GetWindow()->getSize().y / 2);
}

void Camera::SetVector(sf::Vector2f aVector)
{
	myPosition = aVector;
}

void Camera::SetVector(float anX, float anY)
{
	myPosition = { anX, anY };
}

void Camera::SetZone(sf::Vector2i aVector)
{
	myZone = aVector;
}

float Camera::GetDepth()
{
	return myDepth;
}

void Camera::SetDepth(float aDepth)
{
	myDepth = aDepth;
}

sf::Vector2f Camera::myPosition = { 0,0 };
float Camera::myDepth = 1;
float Camera::mySpeed = 3;
sf::Vector2i Camera::myZone = { 30 * 32, 30 * 32 };

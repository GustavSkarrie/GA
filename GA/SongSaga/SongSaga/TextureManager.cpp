#include "TextureManager.h"

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
}

void TextureManager::LoadTexture()
{
	myBox = new sf::Texture();
	if(!myBox->loadFromFile("Grid.png")){}

	myFade = new sf::Texture();
	if (!myFade->loadFromFile("Fade.png")) {}

	myFadeMirror = new sf::Texture();
	if (!myFadeMirror->loadFromFile("FadeMirror.png")) {}

	myArrow = new sf::Texture();
	if (!myArrow->loadFromFile("Arrow.png")) {}
}

sf::Texture* TextureManager::EmptyBox()
{
	return myBox;
}

sf::Texture* TextureManager::Fade()
{
	return myFade;
}

sf::Texture* TextureManager::FadeMirror()
{
	return myFadeMirror;
}

sf::Texture* TextureManager::Arrow()
{
	return myArrow;
}

sf::Texture* TextureManager::myBox;
sf::Texture* TextureManager::myFade;
sf::Texture* TextureManager::myFadeMirror;
sf::Texture* TextureManager::myArrow;
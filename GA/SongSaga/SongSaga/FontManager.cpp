#include "FontManager.h"

FontManager::FontManager()
{
}

FontManager::~FontManager()
{
}

void FontManager::LoadFonts()
{
	myLobster = new sf::Font();
	if (!myLobster->loadFromFile("Lobster.ttf")){}

	myRobotoMono = new sf::Font();
	if (!myRobotoMono->loadFromFile("RobotoMono.ttf")) {}

	myAbel = new sf::Font();
	if (!myAbel->loadFromFile("Abel.ttf")) {}

	myPrompt = new sf::Font();
	if (!myPrompt->loadFromFile("Prompt-Regular.ttf")) {}

	myPromptThin = new sf::Font();
	if (!myPromptThin->loadFromFile("Prompt-Thin.ttf")) {}
}

sf::Font* FontManager::Lobster()
{
	return myLobster;
}

sf::Font* FontManager::RobotoMono()
{
	return myRobotoMono;
}

sf::Font* FontManager::Abel()
{
	return myAbel;
}

sf::Font* FontManager::Prompt()
{
	return myPrompt;
}

sf::Font* FontManager::PromptThin()
{
	return myPromptThin;
}

sf::Font* FontManager::myLobster;
sf::Font* FontManager::myRobotoMono;
sf::Font* FontManager::myAbel;
sf::Font* FontManager::myPrompt;
sf::Font* FontManager::myPromptThin;
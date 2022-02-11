#ifndef FONTMANAGER_HEADER
#define FONTMANAGER_HEADER

#include <SFML/Graphics.hpp>

static class FontManager
{
public:
	FontManager();
	~FontManager();

	static void LoadFonts();

	static sf::Font* Lobster();
	static sf::Font* RobotoMono();
	static sf::Font* Abel();
	static sf::Font* Prompt();
	static sf::Font* PromptThin();

private:
	static sf::Font* myLobster;
	static sf::Font* myRobotoMono;
	static sf::Font* myAbel;
	static sf::Font* myPrompt;
	static sf::Font* myPromptThin;
};

#endif // !FONTMANAGER_HEADER

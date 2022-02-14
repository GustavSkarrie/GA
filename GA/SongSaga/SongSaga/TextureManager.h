#ifndef TEXTUREMANAGER_HEADER
#define TEXTUREMANaGER_HEADER

#include <SFML/Graphics.hpp>

#include "TextureSequence.h"

static class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	static void LoadTexture();

	static sf::Texture* EmptyBox();
	static sf::Texture* Fade();
	static sf::Texture* FadeMirror();
	static sf::Texture* Arrow();

private:
	static sf::Texture* myBox;
	static sf::Texture* myFade;
	static sf::Texture* myFadeMirror;
	static sf::Texture* myArrow;
};


#endif // !TEXTUREMANAGER_HEADER

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

private:
	static sf::Texture* myBox;
	static sf::Texture* myFade;
	static sf::Texture* myFadeMirror;
};


#endif // !TEXTUREMANAGER_HEADER

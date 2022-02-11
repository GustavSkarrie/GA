#ifndef TEXTURESEQUENCE_HEADER
#define TEXTURESEQUENCE_HEADER

#include <SFML/Graphics.hpp>

#include <vector>
#include <string>

class TextureSequence
{
public:
	TextureSequence();
	~TextureSequence();

	void LoadSequence(std::string aFileName, int anHeight, int aWidth);
	void LoadSequence(std::string aFileName, int anHeight, int aWidth, int anAmount);
	void SetRepeat();

	sf::Texture* GetTexture(int anInt);
	int GetSize();

private:
	std::vector<sf::Texture*> myTextures;
};



#endif // !TEXTURESEQUENCE_HEADER

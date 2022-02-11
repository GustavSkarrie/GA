#include "TextureSequence.h"

TextureSequence::TextureSequence()
{
}

TextureSequence::~TextureSequence()
{
}

void TextureSequence::LoadSequence(std::string aFileName, int anHeight, int aWidth)
{
	sf::Texture tempTexture;
	tempTexture.loadFromFile(aFileName);

	sf::Vector2i tempSize(tempTexture.getSize().x / aWidth, tempTexture.getSize().y / anHeight);
	sf::Vector2i tempPos(0,0);

	for (size_t i = 0; i < anHeight; i++)
	{
		tempPos.y = i * tempTexture.getSize().y / anHeight;

		for (size_t y = 0; y < aWidth; y++)
		{
			tempPos.x = y * tempTexture.getSize().x / aWidth;

			sf::Texture* tempLoadedTexture = new sf::Texture();
			tempLoadedTexture->loadFromFile(aFileName, sf::IntRect(tempPos, tempSize));
			myTextures.push_back(tempLoadedTexture);
		}
	}
}

void TextureSequence::LoadSequence(std::string aFileName, int anHeight, int aWidth, int anAmount)
{
	sf::Texture tempTexture;
	tempTexture.loadFromFile(aFileName);

	sf::Vector2i tempSize(tempTexture.getSize().x / aWidth, tempTexture.getSize().y / anHeight);
	sf::Vector2i tempPos(0, 0);

	for (size_t i = 0; i < anHeight; i++)
	{
		tempPos.y = i * tempTexture.getSize().y / anHeight;

		for (size_t y = 0; y < aWidth; y++)
		{
			tempPos.x = y * tempTexture.getSize().x / aWidth;

			sf::Texture* tempLoadedTexture = new sf::Texture();
			tempLoadedTexture->loadFromFile(aFileName, sf::IntRect(tempPos, tempSize));
			myTextures.push_back(tempLoadedTexture);

			if (myTextures.size() == anAmount)
				return;
		}
	}
}

void TextureSequence::SetRepeat()
{
	for (size_t i = 0; i < myTextures.size(); i++)
	{
		myTextures[i]->setRepeated(true);
	}
}

sf::Texture* TextureSequence::GetTexture(int anInt)
{
	return myTextures[anInt];
}

int TextureSequence::GetSize()
{
	return myTextures.size();
}

#ifndef ANIMATIONCLIP_HEADER
#define ANIMATIONCLIP_HEADER

#include <SFML/Graphics.hpp>
#include "TextureSequence.h"

class AnimationClip
{
public:
	AnimationClip();
	AnimationClip(TextureSequence& anAnimation, float aSpeed);
	~AnimationClip();

	void Start();
	void SetStop(bool aStops);
	void Update();

	sf::Texture* GetTexture();
	int GetFrame();
	int GetMax();

private:
	TextureSequence myTexture;
	int myFrame = 0;
	float myTime = 0;
	float mySpeed;
	bool myStops = false;
};




#endif 


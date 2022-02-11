#include "AnimationClip.h"
#include "Game.h"

AnimationClip::AnimationClip()
{
}

AnimationClip::AnimationClip(TextureSequence& anAnimation, float aSpeed)
{
	myTexture = anAnimation;
	mySpeed = aSpeed;
	myTime = Game::GameTime();
}

AnimationClip::~AnimationClip()
{
}

void AnimationClip::Start()
{
	myFrame = 0;
	myTime = Game::GameTime();
}

void AnimationClip::SetStop(bool aStops)
{
	myStops = aStops;
	myFrame = myTexture.GetSize() - 1;
}

void AnimationClip::Update()
{
	if (myTime + mySpeed < Game::GameTime()) 
	{
		if (!myStops || myStops && myFrame != myTexture.GetSize() - 1) 
		{
			myFrame++;
			myTime = Game::GameTime();

			if (myFrame == myTexture.GetSize())
				myFrame = 0;
		}
	}
}

sf::Texture* AnimationClip::GetTexture()
{
	return myTexture.GetTexture(myFrame);
}

int AnimationClip::GetFrame()
{
	return myFrame;
}

int AnimationClip::GetMax()
{
	return myTexture.GetSize();
}

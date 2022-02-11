#ifndef ANIMATION_HEADER
#define ANIMATION_HEADER

#include "Object.h"
#include "AnimationClip.h"

class Animation : public Object
{
public:
	Animation();
	Animation(sf::Vector2f aPosition, sf::Vector2f aSize, TextureSequence aSequence, sf::Color aColor, float aSpeed, float anOrder);
	Animation(sf::Vector2f aPosition, sf::Vector2f aSize, sf::Vector2f anOrgin, float aRotation, TextureSequence aSequence, sf::Color aColor, float aSpeed, float anOrder);

	~Animation();

	void Update();
	void Draw(sf::RenderWindow& aWindow);


private:
	AnimationClip myAnimation;
	sf::Vector2f myOrgin;
	sf::Color myColor;
};



#endif // !ANIMATION_HEADER

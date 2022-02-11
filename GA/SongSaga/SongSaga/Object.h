#ifndef OBJECT_HEADER
#define OBJECT_HEADER

#include <SFML/Graphics.hpp>

class Object
{
public:
	Object();
	Object(sf::Vector2f aPosition, int aDepth);
	Object(sf::Vector2f aPosition, int aDepth, sf::Sprite aSprite);
	~Object();

	void Init();
	void Remove();
	virtual void Update();
	virtual void Draw(sf::RenderWindow& aWindow);

	sf::Sprite GetSprite();
	void SetSprite(sf::Sprite aSprite);

	sf::Vector2f GetPosition();
	void SetPosition(sf::Vector2f aVector);
	void SetPosition(float anX, float anY);

	sf::Vector2f GetSize();
	void SetSize(sf::Vector2f aSize);
	void SetSize(float anX, float anY);

	float GetDepth();
	float GetOrder();
	void SetDepth(float aDepth);

	int GetId();

protected:
	sf::Sprite mySprite;
	sf::Vector2f myPosition;
	sf::Vector2f mySize;
	float myRotation;
	float myDepth;
	float myOrder;
	int myId;
};



#endif // !OBJECT_HEADER

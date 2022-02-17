#ifndef GRIDBLOCK_HEADER
#define GRIDBLOCK_HEADER

#include "Object.h"

class GridBlock : public Object
{
public:
	GridBlock();
	GridBlock(sf::Vector2f aPosition);
	~GridBlock();

	void Update();
	void Draw(sf::RenderWindow& aWindow);

	void ResetEnd();
	void ResetStart();
	void Reset();

	void SetColor(sf::Color aColor);
	void SetValue(float aValue, float aGCost, float aHCost, sf::Vector2i aDirection);
	float GetValue();
	float GetGCost();
	sf::Vector2i GetDirection();

	bool IsSet();
	bool IsActive();
	bool IsEnd();
	bool IsStart();

private:
	float myValue;
	float myGCost;
	float myHCost;
	sf::Vector2i myDirection;
	bool myActive = true;
	bool myStartpoint = false;
	bool myEndpoint = false;
	bool myValueSet = false;
	bool myUI = true;
};

#endif // !GRIDBLOCK_HEADER

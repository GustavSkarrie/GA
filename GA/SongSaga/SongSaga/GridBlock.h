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

	void ResetEnd();
	void ResetStart();

	void SetColor(sf::Color aColor);
	void SetValue(float aValue);
	float GetValue();

	bool IsActive();
	bool IsEnd();
	bool IsStart();

private:
	float myValue;
	bool myActive = true;
	bool myStartpoint = false;
	bool myEndpoint = false;
};

#endif // !GRIDBLOCK_HEADER

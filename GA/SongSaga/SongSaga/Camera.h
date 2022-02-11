#ifndef CAMERA_HEADER
#define CAMERA_HEADER

#include <SFML/Graphics.hpp>

static class Camera
{
public:
	Camera();
	~Camera();

	static void Update(sf::RenderWindow& aWindow);

	static sf::Vector2f GetVector();
	static void SetVector(sf::Vector2f aVector);
	static void SetVector(float anX, float anY);
	static void SetZone(sf::Vector2i aVector);

	static float GetDepth();
	static void SetDepth(float aDepth);

private:
	static sf::Vector2f myPosition;
	static float myDepth;
	static float mySpeed;
	static sf::Vector2i myZone;
};



#endif 
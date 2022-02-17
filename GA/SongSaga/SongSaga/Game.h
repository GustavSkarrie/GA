#ifndef GAME_HEADER
#define GAME_HEADER

#include <SFML/Graphics.hpp>
#include "Grid.h"
#include "Canvas.h"

enum EditorMode { Wall, StartPoint, Endpoint, None };
enum Direction { TopRight, TopLeft, TopMiddle, LowerLeft, LowerRight, LowerMiddle, Left, Right, Mid };

static class Game
{
public:
	Game();
	~Game();
	
	static void Init();
	static void GameLoop();
	static void Update(sf::RenderWindow& aWindow, sf::View& aView);
	static void Draw(sf::RenderWindow& aWindow, sf::View& aView);

	static void Wall();
	static void StartPoint();
	static void Endpoint();
	static void AStar();
	static void BFS();
	static void Reset();
	static void Start();

	static sf::Vector2f WindowPosition(Direction aDirection);
	static float Clamp(float aValue, float anMax, float anMin);
	static float GameTime();
	static float DeltaTime();
	static float GetZoom();
	static sf::RenderWindow* GetWindow();
	static sf::Vector2f ToView(sf::Vector2i aPosition);
	static float ToView(float aPosition, bool anX);
	static float Length(sf::Vector2f aVector1, sf::Vector2f aVector2);
	static sf::Vector2f RotationTo(float aRotation);
	static Grid GetGrid();
	static EditorMode GetMode();

private:
	static sf::RenderWindow* myWindow;
	static sf::Clock myClock;
	static float myLastTime;
	static float myDeltaTime;
	static float myCurZoom;
	static Grid myGrid;
	static EditorMode myMode;
	static Canvas* myEditorUI;
};




#endif // !GAME_HEADER

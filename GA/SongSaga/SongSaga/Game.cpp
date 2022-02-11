#include "Game.h"

#include "UIManager.h"
#include "ObjectManager.h"
#include "UIObject.h"
#include "Canvas.h"
#include "Image.h"
#include "TextureManager.h"
#include "FontManager.h"
#include "MouseManager.h"
#include "Text.h"
#include "Button.h"
#include "Camera.h"
#include "Grid.h"
#include "AStar.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::Init()
{
    TextureManager::LoadTexture();
    FontManager::LoadFonts();
    GameLoop();
}

void Game::GameLoop()
{
    myClock.restart();
    sf::RenderWindow tempWindow(sf::VideoMode(1700, 900), "SFML works!");
    myWindow = &tempWindow;
    sf::View tempView(sf::FloatRect(0.f, 0.f, 1700, 900));

    myGrid = Grid(10, 10);
    myEditorUI = new Canvas(sf::Vector2f(0, 70), sf::Vector2f(120, 400), sf::Color(200, 200, 200, 0), 1);
    myEditorUI->AddObject(new Image(TextureManager::FadeMirror(), sf::Vector2f(5, -70), sf::Vector2f(5, 500), 3, sf::Color(255, 255, 255, 255)));
    myEditorUI->AddObject(new Button(&Wall, "Wall", sf::Vector2f(10, 10), sf::Vector2f(140, 40), 3, TextureManager::Fade(), true));
    myEditorUI->AddObject(new Button(&StartPoint, "Start Point", sf::Vector2f(10, 60), sf::Vector2f(140, 40), 3, TextureManager::Fade(), true));
    myEditorUI->AddObject(new Button(&Endpoint, "End Point", sf::Vector2f(10, 110), sf::Vector2f(140, 40), 3, TextureManager::Fade(), true));
    myEditorUI->AddObject(new Button(&Start, "Start", sf::Vector2f(10, 160), sf::Vector2f(140, 40), 3, TextureManager::Fade(), true));

    while (tempWindow.isOpen())
    {
        sf::Event tempEvent;

        while (tempWindow.pollEvent(tempEvent))
        {
            if (tempEvent.type == sf::Event::Closed)
                tempWindow.close();

            if (tempEvent.type == sf::Event::MouseWheelMoved)
                myCurZoom = Clamp(myCurZoom - tempEvent.mouseWheel.delta * 0.06f, 1.5f, 0.05f);
        }

        tempView.zoom(myCurZoom);
        tempWindow.setView(tempView);

        myDeltaTime = myClock.getElapsedTime().asMilliseconds() - myLastTime;
        Update(tempWindow, tempView);
        myLastTime = myClock.getElapsedTime().asMilliseconds();

        tempWindow.clear();
        Draw(tempWindow, tempView);
        tempWindow.display();
    }
}

void Game::Update(sf::RenderWindow& aWindow, sf::View& aView)
{
    MouseManager::Update(aWindow, aView);
    Camera::Update(aWindow);
    ObjectManager::Update();
    UIManager::Update();
    MouseManager::LateUpdate();
}

void Game::Draw(sf::RenderWindow& aWindow, sf::View& aView)
{
    ObjectManager::Draw(aWindow);
    UIManager::DrawWorld(aWindow);
    aView.zoom(1 / myCurZoom);
    aWindow.setView(aView);
    UIManager::Draw(aWindow);
}

void Game::Wall()
{
    myMode = EditorMode::Wall;
    myEditorUI->ResetButtons();
}

void Game::StartPoint()
{
    myMode = EditorMode::StartPoint;
    myEditorUI->ResetButtons();
}

void Game::Endpoint()
{
    myMode = EditorMode::Endpoint;
    myEditorUI->ResetButtons();
}

void Game::Start()
{
    myGrid.AStar();
}

sf::Vector2f Game::WindowPosition(Direction aDirection)
{
    switch (aDirection)
    {
    case Direction::TopRight:
        return sf::Vector2f(myWindow->getSize().x, 0);

    case Direction::TopLeft:
        return sf::Vector2f(0, 0);

    case Direction::TopMiddle:
        return sf::Vector2f(myWindow->getSize().x / 2, 0);

    case Direction::LowerMiddle:
        return sf::Vector2f(myWindow->getSize().x / 2, myWindow->getSize().y);
    }

    return sf::Vector2f();
}

float Game::Clamp(float aValue, float anMax, float anMin)
{
    float tempValue = aValue;

    if (tempValue > anMax)
        tempValue = anMax;

    if (tempValue < anMin)
        tempValue = anMin;

    return tempValue;
}

float Game::GameTime()
{
    return myClock.getElapsedTime().asSeconds();
}

float Game::DeltaTime()
{
    return myDeltaTime;
}

float Game::GetZoom()
{
    return myCurZoom;
}

sf::RenderWindow* Game::GetWindow()
{
    return myWindow;
}

sf::Vector2f Game::ToView(sf::Vector2i aPosition)
{
    return myWindow->mapPixelToCoords(aPosition);
}

float Game::ToView(float aPosition, bool anX)
{
    sf::Vector2i tempVector;
    tempVector = myWindow->mapCoordsToPixel(sf::Vector2f(aPosition, aPosition));

    if (anX)
        return tempVector.x;

    return tempVector.y;

}

float Game::Length(sf::Vector2f aVector1, sf::Vector2f aVector2)
{
    sf::Vector2f tempVector;
    tempVector = aVector1 - aVector2;

    float tempLength;
    tempLength = sqrt(tempVector.x * tempVector.x + tempVector.y * tempVector.y);

    return tempLength;
}

sf::Vector2f Game::RotationTo(float aRotation)
{
    sf::Vector2f tempDirection;
    tempDirection.x = cos(aRotation / 53.7f);
    tempDirection.y = sqrt(1 - pow(tempDirection.x, 2));

    if (aRotation > 90)
        tempDirection.y = -sqrt(1 - pow(tempDirection.x, 2));

    return tempDirection;
}

Grid Game::GetGrid()
{
    return myGrid;
}

EditorMode Game::GetMode()
{
    return myMode;
}

sf::RenderWindow* Game::myWindow;
sf::Clock Game::myClock;
float Game::myLastTime = 0;
float Game::myDeltaTime = 0;
float Game::myCurZoom = 1;
Grid Game::myGrid;
EditorMode Game::myMode = EditorMode::None;
Canvas* Game::myEditorUI;
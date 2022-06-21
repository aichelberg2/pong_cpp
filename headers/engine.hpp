#pragma once

#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

// --- Window ---
const float windowWidth = 800;
const float windowHeight = 600;
const float fieldMargin = 5;
const float playerWidth = 5;
const float playerLenght = 100;
const float barrierWidth = 10;

// --- Movement ---
const float keyboardMovingFactor = 18;
const float joystickMovingFactor = 0.2;
const float upperFieldBorder = barrierWidth + fieldMargin;
const float lowerFieldBorder = windowHeight - (playerLenght + barrierWidth + fieldMargin);
const float xPositionPlayer1 = fieldMargin;
const float xPositionPlayer2 = windowWidth - (playerWidth + fieldMargin);

enum Player
{
  PLAYER_1,
  PLAYER_2
};

using namespace sf;
using namespace std;

class Engine
{
private:
  // --- Window ---
  RenderWindow window;
  View view;

  RectangleShape player1;
  RectangleShape player2;
  RectangleShape barrierTop;
  RectangleShape barrierBot;

  // --- Controls ---
  float axis[2] = {0, 0};

  // --- Animation ---
  Clock clock;
  long impactTime;
  bool bImpactAnimation;
  int impactCount;
  Player player;

public:
  Engine();
  void run();

  // --- Window ---
  WindowHandler();
  void initWindow();
  void refreshWindow();

  // --- Event ---
  void handleEvent(const Event event, bool &exit);

  // --- Movement ---
  void updatePosition(int index);
  void handleMovement();

  // --- Animation ---
  void setImpact(Player);
  void impactAnimation();
  long getClockAsMs() { return clock.getElapsedTime().asMilliseconds(); };
};

#include "engine.hpp"

Engine::Engine()
{
  // --- Window ---
  window.create(VideoMode(windowWidth, windowHeight), "Pong", Style::Titlebar | Style::Close);
  view.reset(FloatRect(0, 0, windowWidth, windowHeight));

  // --- Animation ---
  impactTime = getClockAsMs();
  bImpactAnimation = false;
  player = PLAYER_1;
  impactCount = 0;
}

void Engine::run()
{

  bool exit = false;
  // get a relative path to the assets
  char buff[FILENAME_MAX];
  GetCurrentDir(buff, FILENAME_MAX);
  string assetFolder(buff);
  assetFolder += "/../assets/";

  while (!exit)
  {

    Clock clock;

    initWindow();
    refreshWindow();

    while (window.isOpen())
    {
      // handle events
      Event event;
      while (window.pollEvent(event))
      {
        handleEvent(event, exit);
      }

      handleMovement();
      impactAnimation();

      refreshWindow();
    }
  }
}
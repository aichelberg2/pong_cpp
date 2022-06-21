#include "engine.hpp"

void Engine::handleEvent(const Event event, bool &exit)
{

  switch (event.type)
  {
  case Event::Closed:
    exit = true;
    window.close();
    break;

  case Event::LostFocus:
    // open pause menu
    break;

  case Event::KeyPressed:
    switch (event.key.code)
    {
    case Keyboard::Escape:
      exit = true;
      window.close();
      break;

    default:
      break;
    }
    break;

    // Joystick Map: (Dualshock3 with ScpToolkit)
    // X: 0; circle: 1; square: 2; tri: 3
    // R1/L1: 5; Select: 6; Start: 7
    // L3: 8; R3: 9
    //
    // Axis: (Left/Up < 0; Right/Down > 0)
    // Arrows:  X: 6; Y: 7
    // L:       X: 0; Y: 1
    // R:       X: 4; Y: 5

  case Event::JoystickButtonPressed:
    switch (event.joystickButton.button)
    {
    case 0:
      setImpact(PLAYER_1);
      break;
    case 1:
      setImpact(PLAYER_2);
      break;
    case 6:
      window.close();
      exit = true;
      break;
    }
    break;

  case Event::JoystickMoved:
    updatePosition(event.joystickMove.joystickId);
    break;
  }
}
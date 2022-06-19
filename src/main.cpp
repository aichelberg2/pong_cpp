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

using namespace sf;
using namespace std;

namespace
{

  float axis[2] = {0.f, 0.f};

  void updatePosition(int index)
  {
    axis[0] = Joystick::getAxisPosition(index, static_cast<Joystick::Axis>(1));
    axis[1] = Joystick::getAxisPosition(index, static_cast<Joystick::Axis>(5));
  }
}

int main()
{
  bool exit = false;
  // get a relative path to the assets
  char buff[FILENAME_MAX];
  GetCurrentDir(buff, FILENAME_MAX);
  string assetFolder(buff);
  assetFolder += "/../assets/";

  while (!exit)
  {
    RenderWindow window(VideoMode(800, 600), "Pong", Style::Titlebar | Style::Close);
    window.setVerticalSyncEnabled(true);

    RectangleShape player1(Vector2f(5.f, 100.f));
    player1.setFillColor(Color::White);
    player1.setPosition(5.f, 250.f);

    RectangleShape player2(Vector2f(5.f, 100.f));
    player2.setFillColor(Color::White);
    player2.setPosition(790.f, 250.f);

    window.pushGLStates();
    window.draw(player1);
    window.draw(player2);
    window.popGLStates();

    while (window.isOpen())
    {
      // handle events
      Event event;
      while (window.pollEvent(event))
      {
        Vector2f oldPosition = player1.getPosition();

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

          case Keyboard::W:
            window.setActive(true);
            player1.move(0.f, -5.f);
            window.setActive(false);
            break;

          case Keyboard::S:
            window.setActive(true);
            player1.move(0.f, 5.f);
            window.setActive(false);
            break;

          default:
            break;
          }

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
          case 6:
            window.close();
            break;
          }
          break;

        case Event::JoystickMoved:
          updatePosition(event.joystickMove.joystickId);
        }
      }

      if (abs(axis[0]) > 10)
      {
        if (player1.getPosition().y + axis[0] * 0.2 > 500)
        {
          player1.setPosition(0.f, 500.f);
        }
        else if (player1.getPosition().y + axis[0] * 0.2 < 0)
        {
          player1.setPosition(0.f, 0.f);
        }
        else
        {
          player1.move(0.f, axis[0] * 0.2);
        }
      }
      if (abs(axis[1]) > 10)
      {
        if (player2.getPosition().y + axis[1] * 0.2 > 500)
        {
          player2.setPosition(790.f, 500.f);
        }
        else if (player2.getPosition().y + axis[1] * 0.2 < 0)
        {
          player2.setPosition(790.f, 0.f);
        }
        else
        {
          player2.move(0.f, axis[1] * 0.2);
        }
      }

      window.pushGLStates();
      window.clear();
      window.draw(player1);
      window.draw(player2);
      window.popGLStates();

      window.display();
    }

    // release resources...

    return 0;
  }
}

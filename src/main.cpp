#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>

using namespace sf;
using namespace std;

int main()
{
  Window window(VideoMode(800, 600), "Pong");

  while (window.isOpen())
  {
    Event event;
    while (window.pollEvent(event))
    {
      switch (event.type)
      {
      case Event::Closed:
        window.close();
        break;

      case Event::LostFocus:
        // open pause menu
        break;

      case Event::KeyPressed:
        switch (event.key.code)
        {
        case Keyboard::Escape:
          window.close();
          break;

        default:
          cout << event.key.code << endl;
          break;
        }

      default:
        break;
      }
    }
  }

  return EXIT_SUCCESS;
}

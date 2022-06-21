#include "engine.hpp"

void Engine::initWindow()
{
  window.setView(view);
  window.setVerticalSyncEnabled(true);

  player1.setSize(Vector2f(playerWidth, playerLenght));
  player1.setFillColor(Color::White);
  player1.setPosition(fieldMargin, windowHeight / 2 - playerLenght / 2);

  player2.setSize(Vector2f(playerWidth, playerLenght));
  player2.setFillColor(Color::White);
  player2.setPosition(windowWidth - (playerWidth + fieldMargin), windowHeight / 2 - playerLenght / 2);

  barrierTop.setSize(Vector2f(windowWidth, barrierWidth));
  barrierTop.setFillColor(Color::White);
  barrierTop.setPosition(0, fieldMargin);

  barrierBot.setSize(Vector2f(windowWidth, barrierWidth));
  barrierBot.setFillColor(Color::White);
  barrierBot.setPosition(0, windowHeight - (barrierWidth + fieldMargin));

  window.pushGLStates();
  window.draw(player1);
  window.draw(player2);
  window.draw(barrierBot);
  window.draw(barrierTop);
  window.popGLStates();
}

void Engine::refreshWindow()
{
  window.pushGLStates();
  window.clear();
  window.draw(player1);
  window.draw(player2);
  window.draw(barrierBot);
  window.draw(barrierTop);
  window.popGLStates();

  window.setView(view);
  window.display();
}

#include "engine.hpp"

void Engine::updatePosition(int index)
{
  axis[0] = Joystick::getAxisPosition(index, static_cast<Joystick::Axis>(1));
  axis[1] = Joystick::getAxisPosition(index, static_cast<Joystick::Axis>(5));
}

void Engine::handleMovement()
{

  if (Keyboard::isKeyPressed(Keyboard::W))
  {
    if (player1.getPosition().y - keyboardMovingFactor < upperFieldBorder)
    {
      player1.setPosition(xPositionPlayer1, upperFieldBorder);
    }
    else
    {
      player1.move(0, -keyboardMovingFactor);
    }
  }

  else if (Keyboard::isKeyPressed(Keyboard::S))
  {
    if (player1.getPosition().y + keyboardMovingFactor > lowerFieldBorder)
    {
      player1.setPosition(xPositionPlayer1, lowerFieldBorder);
    }
    else
    {
      player1.move(0, keyboardMovingFactor);
    }
  }

  else if (Keyboard::isKeyPressed(Keyboard::Up))
  {
    if (player2.getPosition().y - keyboardMovingFactor < upperFieldBorder)
    {
      player2.setPosition(xPositionPlayer2, upperFieldBorder);
    }
    else
    {
      player2.move(0, -keyboardMovingFactor);
    }
  }

  else if (Keyboard::isKeyPressed(Keyboard::Down))
  {
    if (player2.getPosition().y + keyboardMovingFactor > lowerFieldBorder)
    {
      player2.setPosition(xPositionPlayer2, lowerFieldBorder);
    }
    else
    {
      player2.move(0, keyboardMovingFactor);
    }
  }

  if (abs(axis[0]) > 10)
  {
    if (player1.getPosition().y + axis[0] * joystickMovingFactor > lowerFieldBorder)
    {
      player1.setPosition(xPositionPlayer1, lowerFieldBorder);
    }
    else if (player1.getPosition().y + axis[0] * joystickMovingFactor < upperFieldBorder)
    {
      player1.setPosition(xPositionPlayer1, upperFieldBorder);
    }
    else
    {
      player1.move(0, axis[0] * joystickMovingFactor);
    }
  }
  if (abs(axis[1]) > 10)
  {
    if (player2.getPosition().y + axis[1] * joystickMovingFactor > lowerFieldBorder)
    {
      player2.setPosition(xPositionPlayer2, lowerFieldBorder);
    }
    else if (player2.getPosition().y + axis[1] * joystickMovingFactor < upperFieldBorder)
    {
      player2.setPosition(xPositionPlayer2, upperFieldBorder);
    }
    else
    {
      player2.move(0, axis[1] * joystickMovingFactor);
    }
  }
}
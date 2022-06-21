#include "engine.hpp"

void Engine::setImpact(Player)
{
  player = PLAYER_1;
  bImpactAnimation = true;
  impactCount = 0;
  impactTime = getClockAsMs();
}

void Engine::impactAnimation()
{
  if (bImpactAnimation)
  {
    const int delayTime = 250;
    const float coolDownFactor = 2; // factor by which the first phase is faster than the second
    long elapsedTime = getClockAsMs();

    if (impactTime < elapsedTime)
    {
      switch (impactCount)
      {
      case 0:
        impactCount++;
        impactTime = elapsedTime + delayTime;
        break;
      case 1:
        impactCount++;
        impactTime = elapsedTime + delayTime * coolDownFactor;
        break;
      default:
        view.reset(FloatRect(0, 0, windowWidth, windowHeight));
        bImpactAnimation = false;
        impactCount = 0;
        break;
      }
    }
    else
    {
      float multiplicator = ((float)impactTime - (float)elapsedTime) * 1 / delayTime;
      const float xSizeFactor = 25;
      const float ySizeFactor = 18.75;
      const float xMoveFactor = 20;
      const float yMoveFactor = 0.12;
      const float yDifPlayer1 = player1.getPosition().y - (windowHeight / 2 - playerLenght / 2);
      const float yDifPlayer2 = player2.getPosition().y - (windowHeight / 2 - playerLenght / 2);

      switch (impactCount)
      {
      case 0:
        view.setSize(windowWidth + (xSizeFactor * coolDownFactor * (1 - multiplicator)),
                     windowHeight + (ySizeFactor * coolDownFactor * (1 - multiplicator)));
        if (player == PLAYER_1)
        {
          view.setCenter(windowWidth / 2 + xMoveFactor * coolDownFactor * (1 - multiplicator),
                         windowHeight / 2 - yDifPlayer1 * (1 - multiplicator) * yMoveFactor * coolDownFactor);
        }
        else
        {
          view.setCenter(windowWidth / 2 - xMoveFactor * coolDownFactor * (1 - multiplicator),
                         windowHeight / 2 - yDifPlayer2 * (1 - multiplicator) * yMoveFactor * coolDownFactor);
        }
        break;
      case 1:
        view.setSize(windowWidth + (xSizeFactor * multiplicator),
                     windowHeight + (ySizeFactor * multiplicator));
        if (player == PLAYER_1)
        {
          view.setCenter(windowWidth / 2 + xMoveFactor * multiplicator,
                         windowHeight / 2 - yDifPlayer1 * multiplicator * yMoveFactor);
        }
        else
        {
          view.setCenter(windowWidth / 2 - xMoveFactor * multiplicator,
                         windowHeight / 2 - yDifPlayer2 * multiplicator * yMoveFactor);
        }
        break;
      }
    }
  }
}
#pragma once
#include "includes/keyEvents.h"

void keyEvents(Music music)
{

  if (IsKeyPressed(KEY_SPACE))
  {
    if (IsMusicStreamPlaying(music))
    {
      PauseMusicStream(music);
    }
    else
    {
      ResumeMusicStream(music);
    }
  }

  if (IsKeyPressed(KEY_ESCAPE))
  {
    CloseWindow();
  }
}
#include "includes/App.h"
App::App()
{

  this->mw = new MusicWrapper();
  this->window = new Window();
  this->ke = new KeyEvents();

  this->global_frames[4080 * 2] = {0};
  this->global_frames_count = 0;
}

void App::config()
{
  SetTraceLogLevel(LOG_ERROR);
  this->mw->config();
  this->window->config("Music vizualizer");
}

void App::run(const char *sound_path)
{
  this->mw->setMusic(sound_path);

  this->mw->playMusic();

  while (!WindowShouldClose())
  {
    this->mw->update();
    this->events();
    BeginDrawing();
    EndDrawing();
    // this->window->draw(this->global_frames_count, this->global_frames);
  }
}

void App::events()
{

  KeyCodeEnum mec = this->ke->musicEvents();
  switch (mec)
  {
  case CLOSE_WINDOW:
    printf("ola mundo");
    break;
  case SWITCH_STATE:
    if (this->mw->isMusicPlaying())
    {
      this->mw->pauseMusic();
    }
    else
    {
      this->mw->playMusic();
    }
    break;
  case CONTINUE:
    break;
  default:
    break;
  }
}

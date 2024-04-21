#include "includes/App.h"

App::App(const char *file_path)
{

  this->FsService = new FileSys();
  char *sound_path = this->FsService->get_audio_file(file_path);

  this->mw = new MusicWrapper(LoadMusicStream(sound_path));
  this->window = new Window();

  this->global_frames[4080 * 2] = {0};
  this->global_frames_count = 0;
  // LoadMusicStream(sound_path);
}

void App::configAudio()
{
  SetTraceLogLevel(LOG_ERROR);
  InitAudioDevice();
  assert(this->mw->getChannels() == 2);
}
void App::configScreen()
{
  InitWindow(800, 600, "Musica");
  SetTargetFPS(60);
}

void App::run()
{

  mw->playMusic();
  mw->setMusicVolume(0.9f);

  while (!this->window->closeWindow())
  {

    this->mw->update();
    // this->handleKeyEvents();
    // transfer this logic to App and window will be agnostic about the program behavior
    this->window->draw(global_frames_count, global_frames);
  }
}

// void App::handleKeyEvents()
// {

//   if (IsKeyPressed(KEY_SPACE))
//   {
//     if (IsMusicStreamPlaying(music))
//     {
//       PauseMusicStream(music);
//     }
//     else
//     {
//       ResumeMusicStream(music);
//     }
//   }

//   if (IsKeyPressed(KEY_ESCAPE))
//   {
//     CloseWindow();
//   }
// }

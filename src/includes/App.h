#pragma once
#include <raylib.h>
#include <assert.h>

#include "./FileSys.h"
#include "./MusicWrapper.h"
#include "./Window.h"
#include "./KeyEvents.h"
class App
{
public:
  App();

private:
  FileSys *FsService;
  Window *window;
  MusicWrapper *mw;
  KeyEvents *ke;

  int32_t global_frames[4080 * 2];
  size_t global_frames_count = 0;

public:
  void config();
  void events();
  void run(const char *sound_path);
};
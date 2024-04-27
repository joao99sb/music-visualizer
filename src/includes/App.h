#pragma once
#include <raylib.h>
#include <assert.h>

#include "./FileSys.h"
#include "./MusicWrapper.h"
#include "./Window.h"
#include "./KeyEvents.h"
#include "./utils/utils.h"

class App
{
public:
  App();

private:
  FileSys *FsService;
  Window *window;
  MusicWrapper *mw;
  KeyEvents *ke;

public:
  void config();
  void events();
  void run(const char *sound_path);
};
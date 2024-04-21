#include <raylib.h>
#include <assert.h>

#include "./core.h"
#include "./FileSys.h"
#include "./MusicWrapper.h"
#include "./Window.h"
class App
{
public:
  App(const char *file_path);

private:
  MusicWrapper *mw;
  FileSys *FsService;
  Window *window;

  int32_t global_frames[4080 * 2];
  size_t global_frames_count = 0;

public:
  void configAudio();
  void configScreen();

  void run();
};
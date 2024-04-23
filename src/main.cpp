#include <stdio.h>
#include <raylib.h>
#include <cstdint>
#include <unistd.h>
#include <string.h>

#include <stdlib.h>

#include "includes/FileSys.h"
#include "includes/App.h"
#include "includes/core.h"


int32_t global_frames[4080 * 2] = {0};
size_t global_frames_count = 0;



void callback(void *bufferData, unsigned int frames)
{
  // what is the difference between sample and frame?
  //  frame is a buffer of samples! source: https://stackoverflow.com/questions/60156075/what-does-ffmpeg-think-is-the-difference-between-an-audio-frame-and-audio-sample
  if (frames > ARRAY_LEN(global_frames))
  {
    frames = ARRAY_LEN(global_frames);
  }
  memcpy(global_frames, bufferData, frames * sizeof(int32_t));
  global_frames_count = frames;
}

int main(int argc, const char **argv)
{
  // Initialization
  const char *audio_name = argv[1];

  FileSys fs = FileSys();
  char *sound_path = fs.get_audio_file(audio_name);

  App app = App();

  app.config();

  app.run(sound_path);

  return 0;
}
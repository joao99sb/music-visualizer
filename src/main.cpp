#include <stdio.h>
#include <raylib.h>
#include <cstdint>
#include <unistd.h>
#include <string.h>

#include <stdlib.h>

#include "includes/keyEvents.h"
#include "includes/logger.h"
#include "includes/FileSys.h"
#include "includes/App.h"



int32_t global_frames[4080 * 2] = {0};
size_t global_frames_count = 0;

void music_infos(AudioStream stream)
{
  printf("sample rate: %u\n", stream.sampleRate);
  printf("sample size: %u\n", stream.sampleSize);
  printf("channels: %u\n", stream.channels);
}

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

  App app = App(audio_name);

  app.configAudio();
  app.configScreen();


  // this callback receives the current buffer of the stream
  // AttachAudioStreamProcessor(music.stream, callback);

  // while (!WindowShouldClose())
  // {
  //   UpdateMusicStream(music);
  //   keyEvents(music);
  //   screen(global_frames_count, global_frames);
  // }

  app.run();

  return 0;
}
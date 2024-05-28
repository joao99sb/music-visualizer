#include <stddef.h>
#include <complex.h>
#include <assert.h>
#include "includes/App.h"
#include "includes/core.h"
// #include "includes/fft.h"
#include "includes/MusicWrapper.h"
#include "includes/KeyEvents.h"
#include "includes/Window.h"

Frame global_frames[4080 * 2] = {0};
size_t global_frames_count = 0;

float in[N];
float complex out[N];
float max_amp;

Music music;

void fft(float in[], size_t stride, float complex out[], size_t n)
{

  assert(n > 0);
  double pi = atan2f(1, 1) * 4;
  if (n == 1)
  {
    out[0] = in[0];
    return;
  }

  fft(in, stride * 2, out, n / 2);
  fft(in + stride, stride * 2, out + n / 2, n / 2);

  for (size_t k = 0; k < n / 2; ++k)
  {
    float t = (float)k / n;
    float complex v = cexp(-2 * I * pi * t) * out[k + n / 2];
    float complex e = out[k];
    out[k] = e + v;
    out[k + n / 2] = e - v;
  }
}

void musicBufferHandler(void *bufferData, unsigned int frames)
{
  if (frames < N)
    frames = N;

  Frame *fs = (Frame *)bufferData;
  for (size_t i = 0; i < frames; ++i)
  {
    in[i] = fs[i].left_sample;
  }

  fft(in, 1, out, N);
  max_amp = 0.0f;
  for (size_t i = 0; i < frames; ++i)
  {
    float a = amp(out[i]);

    if (max_amp < a)
      max_amp = a;
  }
}

void configApp()
{

  SetTraceLogLevel(LOG_ERROR);
  configMusic();
  configWindow("Music vizualizer");
}

void runApp(const char *sound_path)
{

  music = getMusic(sound_path);
  assert(getChannels(music) == 2);

  attachAudioProcessor(music, musicBufferHandler);
  playMusic(music);

  List *music_lookup = createLookup();

  configLookup(music_lookup);

  while (!WindowShouldClose())
  {
    updateMusic(music);
    eventsHandler(music_lookup);
    drawWindow(global_frames_count, global_frames, out, max_amp);
    // BeginDrawing();
    // EndDrawing();
  }
}

void eventsHandler(List *music_lookup)
{
  int mec = musicEvents(music_lookup);
  switch (mec)
  {
  case ME_SWITCH_STATE:
    if (isMusicPlaying(music))
    {
      pauseMusic(music);
    }
    else
    {
      playMusic(music);
    }
    break;
  case ME_CONTINUE:
    break;
  default:
    break;
  }
}

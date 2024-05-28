#include <stdio.h>
#include <complex.h>

#include "includes/Window.h"
#include "./includes/App.h"
bool closeWindow()
{
  return WindowShouldClose();
}

void configWindow(const char *title)
{
  InitWindow(800, 600, title);
  SetTargetFPS(60);
}

void drawWindow(size_t frames_count, Frame *frames_buffer, float complex out[], float max_amp)
{
  int w = GetRenderWidth();
  int h = GetRenderHeight();

  BeginDrawing();
  ClearBackground(CLITERAL(Color){0x18, 0x18, 0x18, 0xff});

  float cell_width = (float)w / N;
  for (size_t i = 0; i < N; ++i)
  {
    float t = amp(out[i]) / max_amp;
    DrawRectangle(i * cell_width, h / 2 - h / 2 * t, 1, h / 2 * t, RED);
  }

  EndDrawing();
}
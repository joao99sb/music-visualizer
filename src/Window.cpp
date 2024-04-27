#include "includes/Window.h"
#include <stdio.h>
bool Window::closeWindow()
{
  return WindowShouldClose();
}

void Window::config(const char *title)
{
  InitWindow(800, 600, title);
  SetTargetFPS(60);
}

void Window::draw(size_t frames_count, Frame *frames_buffer)
{
  int w = GetRenderWidth();
  int h = GetRenderHeight();

  BeginDrawing();
  ClearBackground(CLITERAL(Color){0x18, 0x18, 0x18, 0xff});
  float cell_width = (float)w / frames_count;

  for (size_t i = 0; i < frames_count; ++i)
  {

    // int32_t *p_frame_32 = &frames_buffer[i];
    // int16_t *p_frame_16 = (int16_t *)p_frame_32; // <- as we have double channel, we have 2 samples per frame
    //                                              // so we need to pick just the first sample
    //                                              // In the future, I can take both samples into consideration and use the average.
    // int16_t sample = *p_frame_16;

    float sample_normalized = frames_buffer[i].left_sample;

    if (sample_normalized > 0)
    {
      /**  _______   0
       *  | | |*| |
       *  | |*|*| |
       *  | |*|*|*|
       *  |*|*|*|*|
       *  |*|*|*|*|  h/2
       *
       */
      // float sample_normalized = (float)sample / INT16_MAX; // from 0-1

      DrawRectangle(i * cell_width,
                    h / 2 - h / 2 * sample_normalized, 1,
                    h / 2 * sample_normalized, RED);
    }
    else
    {
      // float sample_normalized = (float)sample / INT16_MIN;
      DrawRectangle(i * cell_width, h / 2, 1, h / 2 * sample_normalized, RED);
    }
  }

  EndDrawing();
}
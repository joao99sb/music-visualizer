#pragma once
#include <raylib.h>
#include <cstdint>
#include <unistd.h>

// void screen(size_t global_frames_count, int32_t *global_frames);

class Window
{
public:
  bool closeWindow();

  void draw(size_t global_frames_count, int32_t *frames_buffer);
};
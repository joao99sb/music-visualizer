#pragma once
#include <raylib.h>
#include <cstdint>
#include <unistd.h>
#include "./utils/utils.h"

class Window
{
public:
  bool closeWindow();
  void config(const char *title);

  void draw(size_t frames_count, Frame *frames_buffer);
};
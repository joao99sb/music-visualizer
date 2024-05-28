#pragma once
#include <raylib.h>
#include <unistd.h>
#include <complex.h>
#include "./utils.h"

bool closeWindow();
void configWindow(const char *title);

void drawWindow(size_t frames_count, Frame *frames_buffer, float complex out[], float max_amp);
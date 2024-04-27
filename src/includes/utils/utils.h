#pragma once

#define DEBUG -1
#define ERROR 0
#define INFO 1

void logger(int prefix_code, const char *message);

// in raylib, Samples internally stored as <float>s
typedef struct
{
  float left_sample;
  float right_sample;
} Frame;
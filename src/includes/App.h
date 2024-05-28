#pragma once
#include <raylib.h>
#include <assert.h>
#include "./hashTable.h"

#define N 256

void configApp();
void eventsHandler(List* music_lookup);
void runApp(const char *sound_path);
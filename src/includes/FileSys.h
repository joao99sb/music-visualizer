#pragma once
#include <limits.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char *get_audio_file(const char *audio_name);

char *resolve_path(const char *path);
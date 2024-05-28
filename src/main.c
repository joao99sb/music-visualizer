#include <stdio.h>
#include <raylib.h>
#include <unistd.h>
#include <string.h>

#include <stdlib.h>

#include "includes/FileSys.h"
#include "includes/App.h"

int main(int argc, const char **argv)
{
  // Initialization

  const char *audio_name = argv[1];

  char *sound_path = get_audio_file(audio_name);

  configApp();

  runApp(sound_path);

  return 0;
}
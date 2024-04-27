#include <stdio.h>
#include <raylib.h>
#include <cstdint>
#include <unistd.h>
#include <string.h>

#include <stdlib.h>

#include "includes/FileSys.h"
#include "includes/App.h"

int main(int argc, const char **argv)
{
  // Initialization
  const char *audio_name = argv[1];

  FileSys fs = FileSys();
  char *sound_path = fs.get_audio_file(audio_name);

  App app = App();

  app.config();

  app.run(sound_path);

  return 0;
}
#include "includes/FileSys.h"
#include "includes/logger.h"
char *FileSys::get_audio_file(const char *audio_path)
{
  if (audio_path == NULL)
  {
    logger(ERROR, "please inform the path of audio");
    exit(1);
  }
  char *file_path = this->resolve_path(audio_path);

  return file_path;
}
char *FileSys::resolve_path(const char *path)
{
  static char resolvedPath[PATH_MAX]; // Buffer estático para o caminho absoluto
  realpath(path, resolvedPath);

  if (access(resolvedPath, F_OK) == -1)
  {
    logger(ERROR, "please inform a valid path to audio");
    exit(1);
  }
  return resolvedPath;
}

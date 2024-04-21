#include "includes/logger.h"

void logger(int prefix_code, const char *message)
{
  const char *prefix;
  switch (prefix_code)
  {
  case ERROR:
    prefix = "ERROR";
    break;
  case INFO:
    prefix = "INFO";
    break;

  default:
    prefix = "DEBUG";
    break;
  }

  printf("%s: %s\n", prefix, message);
}
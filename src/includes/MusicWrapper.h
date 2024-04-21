#include <raylib.h>
#include "./core.h"
class MusicWrapper
{

public:
  MusicWrapper(Music music);

  usize getChannels();
  void playMusic();
  void setMusicVolume(float vol);
  void pauseMusic();
  void update();

private:
  Music music;
};
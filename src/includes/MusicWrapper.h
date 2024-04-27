#pragma once
#include <raylib.h>
#include <cstddef>
#include <cstring>
#include <iostream>
#include "./utils/utils.h"

class MusicWrapper
{

public:
  MusicWrapper();

  void playMusic();

  void setMusic(const char *sound_path);
  void setMusicVolume(float vol);
  void pauseMusic();
  bool isMusicPlaying();
  void update();
  void config();
  void attachAudioProcessor(AudioCallback processor);
  int getChannels();

private:
  Music music;
};
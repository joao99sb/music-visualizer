#include "includes/MusicWrapper.h"

MusicWrapper::MusicWrapper(Music music)
{

  this->music = music;
};
usize MusicWrapper::getChannels()
{

  return this->music.stream.channels;
};

void MusicWrapper::playMusic()
{
  PlayMusicStream(this->music);
}
void MusicWrapper::setMusicVolume(float vol)
{
  SetMusicVolume(this->music, vol);
}
void MusicWrapper::pauseMusic()
{
  PauseMusicStream(this->music);
}
void MusicWrapper::update()
{
  UpdateMusicStream(music);
}
#include "includes/MusicWrapper.h"
#include <stdlib.h>
MusicWrapper::MusicWrapper(){

};
void MusicWrapper::config()
{
  InitAudioDevice();
};
// usize MusicWrapper::getChannels()
// {

//   return (this->music).stream.channels;
// };

void MusicWrapper::setMusic(const char *sound_path)
{
  Music m = LoadMusicStream(sound_path);

  this->music = m;
}

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
  UpdateMusicStream(this->music);
}
bool MusicWrapper::isMusicPlaying()
{
  return IsMusicStreamPlaying(this->music);
}
// void music_infos(AudioStream stream)
// {
//   printf("sample rate: %u\n", stream.sampleRate);
//   printf("sample size: %u\n", stream.sampleSize);
//   printf("channels: %u\n", stream.channels);
// }
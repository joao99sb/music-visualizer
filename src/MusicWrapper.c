#include "includes/MusicWrapper.h"
#include <stdlib.h>

void configMusic()
{
  InitAudioDevice();
};

Music getMusic(const char* sound_path)
{
  return LoadMusicStream(sound_path);
}

int getChannels(Music music)
{
  return music.stream.channels;
};

void playMusic(Music music)
{
  PlayMusicStream(music);
}

void setMusicVolume(Music music, float vol)
{
  SetMusicVolume(music, vol);
}
void pauseMusic(Music music)
{
  PauseMusicStream(music);
}
void updateMusic(Music music)
{
  UpdateMusicStream(music);
}
bool isMusicPlaying(Music music)
{
  return IsMusicStreamPlaying(music);
}
void attachAudioProcessor(Music music, AudioCallback processor)
{
  AttachAudioStreamProcessor(music.stream, processor);
}
void musicInfos(AudioStream stream)
{
  printf("sample rate: %u\n", stream.sampleRate);
  printf("sample size: %u\n", stream.sampleSize);
  printf("channels: %u\n", stream.channels);
}
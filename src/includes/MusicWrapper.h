#pragma once
#include <raylib.h>
#include "./utils.h"

void playMusic(Music music);
void configMusic();
void setMusicVolume(Music music, float vol);
void pauseMusic(Music music);
bool isMusicPlaying(Music music);
void updateMusic(Music music);
void attachAudioProcessor(Music music, AudioCallback processor);
int getChannels(Music music);
void musicInfos(AudioStream stream);
Music getMusic(const char *path);
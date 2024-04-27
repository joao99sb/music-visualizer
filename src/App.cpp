#include "includes/App.h"
#include "includes/core.h"

static Frame global_frames[4080 * 2];
static size_t global_frames_count;

void musicBufferHandler(void *bufferData, unsigned int frames)
{
  // what is the difference between sample and frame?
  //  frame is a buffer of samples! source: https://stackoverflow.com/questions/60156075/what-does-ffmpeg-think-is-the-difference-between-an-audio-frame-and-audio-sample
  size_t capacity = ARRAY_LEN(global_frames);

  // Checks if the number of frames to be copied fits into the remaining space of the buffer.
  if (frames <= capacity - global_frames_count)
  {
    // Copies the data from the input buffer to the end of the global buffer.
    memcpy(global_frames + global_frames_count, bufferData, frames * sizeof(Frame));
    // Updates the frame counter in the global buffer.
    global_frames_count += frames;
  }
  // If the remaining space of the buffer is small to frames, but the frames size fits into buffer
  else if (frames <= capacity)
  {
    // Moves the existing data in the global buffer forward, creating space for the new frames.
    memmove(global_frames, global_frames + frames, sizeof(Frame) * (capacity - frames));
    // Moves the existing data in the global buffer forward, creating space for the new frames.
    memcpy(global_frames + (capacity - frames), bufferData, frames * sizeof(Frame));
  }
  // If the number of frames exceeds the buffer's capacity, replaces the buffer's content.
  else
  {
    // Replaces the content of the global buffer with the new frames.
    memcpy(global_frames, bufferData, capacity * sizeof(Frame));
    // Updates the frame counter in the global buffer to the maximum capacity.
    global_frames_count = capacity;
  }
}

App::App()
{

  this->mw = new MusicWrapper();
  this->window = new Window();
  this->ke = new KeyEvents();

  global_frames[4080 * 2] = {0};
  global_frames_count = 0;
}

void App::config()
{
  SetTraceLogLevel(LOG_ERROR);
  this->mw->config();
  this->window->config("Music vizualizer");
}

void App::run(const char *sound_path)
{
  this->mw->setMusic(sound_path);
  
  assert(this->mw->getChannels() == 2);

  this->mw->attachAudioProcessor(musicBufferHandler);
  this->mw->playMusic();

  while (!WindowShouldClose())
  {
    this->mw->update();
    this->events();
    this->window->draw(global_frames_count, global_frames);
  }
}

void App::events()
{

  KeyCodeEnum mec = this->ke->musicEvents();
  switch (mec)
  {
  case CLOSE_WINDOW:
    break;
  case SWITCH_STATE:
    if (this->mw->isMusicPlaying())
    {
      this->mw->pauseMusic();
    }
    else
    {
      this->mw->playMusic();
    }
    break;
  case CONTINUE:
    break;
  default:
    break;
  }
}

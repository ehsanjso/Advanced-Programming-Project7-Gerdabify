#ifndef GERDABPLAYER_H
#define GERDABPLAYER_H

#include "sdlHeaders.hpp"
#include <iostream>
#include <string>
#include <vector>

void Delay(int milis);
class GerdabPlayer
{
  public:
    GerdabPlayer();
    static void play();
    static void setMusic(std::string path);
    static void pause();
    static void resume();
    static void stop();
    static void setRepeat(bool repeat);
    static void setQueue(std::vector<std::string> queue);
    friend void musicFinishCallback();
    static std::string nextMusic;
    void goToPreviousMusic();
    void goToNextMusic();

  private:
    static Mix_Music *music;
    static std::vector<std::string> queue;
    static bool repeat;
    static int index;
    static void goToNext();
};

class GerdabError{
private:
  std::string message;
public:
  GerdabError();
  GerdabError(std::string errorMessage);
  std::string getMessage();
};

#endif
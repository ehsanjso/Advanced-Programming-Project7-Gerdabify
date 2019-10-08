#include "mode.h"
#include "playlist.h"
#include "gerdabPlayer.hpp"

#ifndef PLAYER_H
#define PLAYER_H

class Player : public Mode {
public:
    static Player* getInstance();
    std::string get_type() { return "player"; }
    void set_player_playlist(Playlist* p);
    Playlist* get_playlist() { return playlist; }
    void play();
    void next();
    void previous();
    void pause();
    void seek(int, int);
    void shuffle();
    void repeatOne();
    void repeat();
    GerdabPlayer* get_player() { return gPlayer; }
private:
	static Player* instance;
    Player();
    Playlist* playlist;
    int head;
    GerdabPlayer* gPlayer;
    bool repeatAll;
};

#endif
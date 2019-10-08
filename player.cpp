#include "player.h"
#include <iostream>

using namespace std;

Player* Player::instance = 0;

Player* Player::getInstance() {
    if (instance == 0) {
        instance = new Player();
    }
    return instance;
};

Player::Player() { 
	head = 0; 
	repeatAll = false;
	GerdabPlayer* g = new GerdabPlayer();
	gPlayer = g;
};

void Player::set_player_playlist(Playlist* p) {
	playlist = p;
	gPlayer->setQueue(playlist->get_playlist_musics_for_player());
};

void Player::play() {
	gPlayer->play();
};

void Player::next() {
	gPlayer->goToNextMusic();
};

void Player::previous() {
	gPlayer->goToPreviousMusic();
};

void Player::pause() {
	gPlayer->pause();
};

void Player::seek(int min, int sec) {

};

void Player::shuffle() {

};

void Player::repeatOne() {

};

void Player::repeat() {
	if(repeatAll) {
		repeatAll = false;
		gPlayer->setRepeat(repeatAll);
	} else {
		repeatAll = true;
		gPlayer->setRepeat(repeatAll);
	}
};

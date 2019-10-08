#include "p_music.h"
#include <algorithm>

using namespace std;

Music_page* Music_page::instance = 0;

Music_page* Music_page::getInstance(string s) {
    if (instance == 0) {
        instance = new Music_page(s);
    }
    return instance;
};

void Music_page::addTo(string s) {
	if(repo->has_playlist(s)) 
		repo->get_playlist(s)->add_music(music, repo->get_curr_user());
	else if (repo->has_album(s))
		repo->add_music_to_album(music, s);
	else
		throw ItemDoesNotExists();
};

string Music_page::getArtist() {
	return (music->get_music_artist())->get_full_name();
};

string Music_page::getAlbum() {
	return (music->get_music_album())->get_album_name();
};

void Music_page::play() { 
	repo->add_music_to_playlist(music, "queue");
};

void Music_page::rate(int score) {
	(music->get_music_rate())->add_rate(score, repo->get_curr_user());
};

int Music_page::getRate() {
	return (music->get_music_rate())->getRate(repo->get_curr_user());
};

int Music_page::getUserRate() {
	return (music->get_music_rate())->getUserRate();
};

int Music_page::getCriticRate() {
	return (music->get_music_rate())->getCriticRate();
};

void Music_page::validate() {
	if((repo->get_curr_user())->get_user_type() == Admin)
		music->validate();
	else 
		throw NotAuthorized();
};
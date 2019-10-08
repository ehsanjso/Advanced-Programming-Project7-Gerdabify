#include "p_artist.h"

using namespace std;

Artist_page* Artist_page::instance = 0;

Artist_page* Artist_page::getInstance(string s) {
    if (instance == 0) {
        instance = new Artist_page(s);
    }
    return instance;
};

vector<string> Artist_page::list() {
	return repo->albums_artist(artist->get_full_name());
};

vector<string> Artist_page::listMusics() {
	return repo->musics_artist(artist->get_full_name());
};

vector<string> Artist_page::listAlbums() {
	return list();
};

void Artist_page::play() { 
	repo->add_artist_musics_to_playlist(artist->get_full_name(), "queue");
};

void Artist_page::rate(int score) {
	(artist->get_artist_rate())->add_rate(score, repo->get_curr_user());
};

int Artist_page::getRate() {
	return (artist->get_artist_rate())->getRate(repo->get_curr_user());
};

int Artist_page::getUserRate() {
	return (artist->get_artist_rate())->getUserRate();
};

int Artist_page::getCriticRate() {
	return (artist->get_artist_rate())->getCriticRate();
};

void Artist_page::validate() {
	if((repo->get_curr_user())->get_user_type() == Admin)
		artist->validate();
	else 
		throw NotAuthorized();
};
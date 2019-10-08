#include "p_album.h"

using namespace std;

Album_page* Album_page::instance = 0;

Album_page* Album_page::getInstance(string s) {
    if (instance == 0) {
        instance = new Album_page(s);
    }
    return instance;
};

vector<string> Album_page::list() {
	return repo->musics_album(album->get_album_name());
};

vector<string> Album_page::listMusics() {
	return list();
};

void Album_page::remove(string music_name) {
	Music* m = repo->get_music(music_name);
	if(repo->is_curr_user_owner(m))
		m->delete_from_album();
	else 
		throw NotAuthorized();
};

void Album_page::addTo(string s) {
	if(repo->has_playlist(s))
		repo->add_album_to_playlist(album->get_album_name(), s);
	else
		throw ItemDoesNotExists();
};

string Album_page::getArtist() {
	return (album->get_album_artist())->get_full_name();
};

void Album_page::play() {
	repo->add_album_to_playlist(album->get_album_name(), "queue");
};

void Album_page::rate(int score) {
	(album->get_album_rate())->add_rate(score, repo->get_curr_user());
};

int Album_page::getRate() {
	return (album->get_album_rate())->getRate(repo->get_curr_user());
};

int Album_page::getUserRate() {
	return (album->get_album_rate())->getUserRate();
};

int Album_page::getCriticRate() {
	return (album->get_album_rate())->getCriticRate();
};

void Album_page::validate() {
	if((repo->get_curr_user())->get_user_type() == Admin)
		album->validate();
	else 
		throw NotAuthorized();
};
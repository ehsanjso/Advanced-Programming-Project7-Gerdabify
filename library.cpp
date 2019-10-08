#include "library.h"

using namespace std;

Library* Library::instance = 0;

Library* Library::getInstance(string s) {
    if (instance == 0) {
        instance = new Library(s);
    }
    return instance;
};

vector<string> Library::list() {
	return repo->all_artists();
};

vector<string> Library::listMusics() {
	return repo->all_musics();
};

vector<string> Library::listAlbums() {
	return repo->all_albums();
};

vector<string> Library::listArtists() {
	return list();
};

vector<string> Library::listMusics_full_name() {
	return repo->all_musics_full_name();
};

vector<string> Library::listAlbums_full_name() {
	return repo->all_albums_full_name();
};

vector<string> Library::listArtists_full_name() {
	return repo->all_artists_full_name();
};
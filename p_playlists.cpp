#include "p_playlists.h"
#include <algorithm>
#include <iostream>

using namespace std;

Playlists_page* Playlists_page::instance = 0;

Playlists_page* Playlists_page::getInstance(string s) {
    if (instance == 0) {
        instance = new Playlists_page(s);
    }
    return instance;
};

vector<string> Playlists_page::list() {
	vector<Playlist*> playlists = repo->get_playlists();
	vector<string> v;
	vector<string> temp;
	for(int i = 0; i < playlists.size(); i++) {
		temp = repo->musics_playlist(playlists[i]->get_playlist_name());
		v.insert( v.end(), temp.begin(), temp.end() );
		temp.clear();
	}
	return v;
};

vector<string> Playlists_page::listMusics() {
	return list();
};

vector<string> Playlists_page::listAlbums() {
	vector<Playlist*> playlists = repo->get_playlists();
	vector<string> v;
	vector<string> temp;
	for(int i = 0; i < playlists.size(); i++) {
		temp = repo->albums_playlist(playlists[i]->get_playlist_name());
		v.insert( v.end(), temp.begin(), temp.end() );
		temp.clear();
	}
	return v;
};

vector<string> Playlists_page::listPlaylists() {
	return repo->all_playlists();
};

vector<string> Playlists_page::listPlaylists_full_name() {
	return repo->all_playlists_full_name();
};

void Playlists_page::remove(string music_name) {
	repo->delete_music_from_playlists(music_name);
};
#include "p_playlist.h"
#include <algorithm>

using namespace std;

Playlist_page* Playlist_page::instance = 0;

Playlist_page* Playlist_page::getInstance(string s) {
    if (instance == 0) {
        instance = new Playlist_page(s);
    }
    return instance;
};

vector<string> Playlist_page::list() {
	return repo->musics_playlist(playlist->get_playlist_name());
};

vector<string> Playlist_page::listMusics() {
	return list();
};

vector<string> Playlist_page::listAlbums() {
	return repo->albums_playlist(playlist->get_playlist_name());
};

vector<string> Playlist_page::listPlaylists() {
	return repo->all_playlists();
};

vector<string> Playlist_page::listPlaylists_full_name() {
	return repo->all_playlists_full_name();
};

void Playlist_page::remove(string music_name) {
	Music* m = repo->get_music(music_name);
	if(repo->is_curr_user_owner(m))
		playlist->delete_music(music_name);
	else 
		throw NotAuthorized();
};

void Playlist_page::orderItem(string music_name, int new_order) {
	if(playlist->has_music(music_name)) {
		Music* m = repo->get_music(music_name);
	} else
		throw ItemDoesNotExists();
};

void Playlist_page::play() { 
	repo->add_playlist_music_to_playlist(playlist->get_playlist_name(), (repo->get_playlist("queue"))->get_playlist_name());
};
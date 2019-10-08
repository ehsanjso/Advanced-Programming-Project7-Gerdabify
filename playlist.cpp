#include "playlist.h"
#include <iostream>

using namespace std;

std::string Playlist::get_playlist_complete_name() { 
	if(user != NULL)
		return user->get_username() + '-' + playlist_name;
	else 
		return get_playlist_name();
};

vector<string> Playlist::get_playlist_musics() {
	vector<string> l;
	for(int i = 0; i < musics.size(); i++) {
		l.push_back(musics[i]->get_music_name());
	}
	return l;
};

vector<string> Playlist::get_playlist_musics_for_player() {
	vector<string> l;
	for(int i = 0; i < musics.size(); i++) {
		l.push_back(musics[i]->get_music_path() + musics[i]->get_music_name());
		// l.push_back(musics[i]->get_music_path());
	}
	return l;
};

vector<string> Playlist::get_playlist_albums() {
	vector<string> l;
	for(int i = 0; i < albums.size(); i++) {
		l.push_back(albums[i]->get_album_name());
	}
	return l;
};

void Playlist::delete_music(std::string music_name) {
	for(int i = 0; i < musics.size(); i++) {
		if(musics[i]->get_music_name() == music_name)
			musics.erase(musics.begin() + i);
	}
};

void Playlist::clearPlaylist() {
	musics.clear();
	albums.clear();
};

void Playlist::add_music(Music* m, User* curr_user) {
	if(playlist_name != "queue")
		if(curr_user == user) 
			musics.push_back(m);
		else 
			throw NotAuthorized(); 
	else 
		musics.insert(musics.begin(), m);
};

void Playlist::add_musics(vector<Music*> m, User* curr_user) {
	if(playlist_name != "queue")
		if(curr_user == user) 
			musics.insert(musics.end(), m.begin(), m.end());
		else 
			throw NotAuthorized(); 
	else 
		musics.insert(musics.begin(), m.begin(), m.end());
};

bool Playlist::has_music(string music_name) {
	for(int i = 0; i < musics.size(); i++) {
		if(musics[i]->get_music_name() == music_name || musics[i]->get_music_complete_name() == music_name)
			return true;
	}
	return false;
};

void Playlist::orderItem(std::string music_name, int new_order) {
	if(new_order < 0 || new_order > musics.size())
		throw InvalidArguments();
	else {
		swap(musics[get_music_index(music_name)], musics[new_order - 1]);
	}
};

int Playlist::get_music_index(string music_name) {
	for(int i = 0; i < musics.size(); i++) {
		if(musics[i]->get_music_name() == music_name || musics[i]->get_music_complete_name() == music_name)
			return i;
	}
	throw ItemDoesNotExists();
};
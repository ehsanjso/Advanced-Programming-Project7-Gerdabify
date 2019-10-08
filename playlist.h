#include <string>
#include <vector>
#include "music.h"
#include "album.h"
#include "user.h"

#ifndef PLAYLIST_H
#define PLAYLIST_H

class Playlist {
public:
	Playlist(std::string name, User* u = NULL) : playlist_name(name), user(u) {}
	std::string get_playlist_name() { return playlist_name; }
	std::vector<std::string> get_playlist_musics();
	std::vector<std::string> get_playlist_musics_for_player();
	std::vector<std::string> get_playlist_albums();
	void delete_music(std::string);
	void clearPlaylist();
	std::string get_playlist_complete_name();
	void add_music(Music* m, User* curr_user);
	void add_musics(std::vector<Music*> m, User* curr_user);
	bool has_music(std::string music_name);
	void orderItem(std::string, int);
	int get_music_index(std::string music_name);
	std::vector<Music*> get_musics() { return musics; }
	User* get_playlist_user() { return user; }
private:
	std::string playlist_name;
	std::vector<Music*> musics;
	std::vector<Album*> albums;
	User* user;
};

#endif
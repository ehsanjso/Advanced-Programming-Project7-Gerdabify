#include "album.h"
#include "playlist.h"
#include "music.h"
#include "user.h"
#include "error.h"
#include <vector>

#ifndef REPO_H
#define REPO_H

typedef std::vector<std::string> List;

class Repo {
public:
	static Repo* getInstance();
	void set_user(User* user);
	void add_music(std::string music_name, std::string path);
	void add_album(std::string artist_name, std::string album_name);
	void add_user(User* u);
	bool auth_user(std::string user, std::string pass);
	bool is_user_duplicate(std::string user);
	bool is_user_artist();
	User* get_curr_user() { return curr_user; }
	UserData getUserDetails(std::string username);
	List search(std::string s);
	List musics_playlist(std::string playlist_name);
	List albums_playlist(std::string playlist_name);
	List musics_album(std::string album_name);
	List musics_artist(std::string artist_name);
	List albums_artist(std::string artist_name);
	List all_musics();
	List all_artists();
	List all_albums();
	List all_playlists();
	List all_musics_full_name();
	List all_artists_full_name();
	List all_albums_full_name();
	List all_playlists_full_name();
	List all_playlists_of_user();
	void createPlaylist(std::string playlist_name);
	bool is_playlist_duplicate(std::string playlist_name);
	void clearPlaylist(std::string playlist_name);
	Music* get_music(std::string music_name);
	Playlist* get_playlist(std::string playlist_name);
	Album* get_album(std::string album_name);
	User* get_artist(std::string artist_name);
	User* get_user(std::string user_name);
	std::vector<Playlist*> get_playlists() { return playlists; }
	bool is_curr_user_owner(Music* m);
	void add_album_to_playlist(std::string album_name, std::string playlist_name);
	void add_artist_musics_to_playlist(std::string artist_name, std::string playlist_name);
	void add_playlist_music_to_playlist(std::string p1, std::string p2);
	void add_music_to_album(Music* m, std::string album_name);
	void add_music_to_playlist(Music* m, std::string playlist_name);
	bool has_album(std::string album_name);
	bool has_playlist(std::string playlist_name);
	bool has_music(std::string music_name);
	bool has_artist(std::string artist_name);
	void delete_music_from_playlists(std::string music_name);
private:
	static Repo* instance;
	Repo();
	std::vector<Playlist*> playlists;
	std::vector<Album*> albums;
	std::vector<Music*> musics;
	std::vector<User*> users;
	User* curr_user;
};	

#endif
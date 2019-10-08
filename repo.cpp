#include "repo.h"
#include <iostream>

using namespace std;

Repo* Repo::instance = 0;

Repo* Repo::getInstance() {
    if (instance == 0) {
        instance = new Repo();
    }
    return instance;
};

Repo::Repo() {
	createPlaylist("queue");
};

void Repo::set_user(User* user) {
	curr_user = user; 
};

void Repo::add_user(User* u) { 
	users.push_back(u); 
};

bool Repo::auth_user(string user, string pass) { 
	for(int i = 0; i < users.size(); i++) {
		if(users[i]->authenticate(user, pass)) {
			curr_user = users[i];
			return true;
		}
	}
	return false;
};

bool Repo::is_user_duplicate(string user) {
	for(int i = 0; i < users.size(); i++) {
		if(users[i]->get_username() == user) {
			return true;
		}
	}
	return false;
};

void Repo::add_music(string music_name, string path) {
	if(is_user_artist()) {
		Music* m = new Music(music_name, path, curr_user);
		musics.push_back(m);
	} else {
		throw NotAuthorized();
	}
};

void Repo::add_album(string artist_name, string album_name) {
	if(is_user_artist()) {
		Album* a = new Album(album_name, curr_user);
		albums.push_back(a);
	} else {
		throw NotAuthorized();
	}
};

bool Repo::is_user_artist() {
	if(curr_user->get_user_type() != Artist) 
		return false;
	else 
		return true;
};

UserData Repo::getUserDetails(string username) {
	for(int i = 0; i < users.size(); i++) {
		if(users[i]->get_username() == username)
			return users[i]->getUserDetails();
	}
	throw MethodNotAvailable();
};

List Repo::search(string s) {
	List l;

	for(int i = 0; i < users.size(); i++)
		if((users[i]->get_full_name()).find(s) != string::npos)
			l.push_back(users[i]->get_full_name());

	for(int i = 0; i < musics.size(); i++)
		if((musics[i]->get_music_complete_name()).find(s) != string::npos)
			l.push_back(musics[i]->get_music_name());

	for(int i = 0; i < albums.size(); i++)
		if((albums[i]->get_album_complete_name()).find(s) != string::npos)
			l.push_back(albums[i]->get_album_name());
	
	for(int i = 0; i < playlists.size(); i++)
		if((playlists[i]->get_playlist_complete_name()).find(s) != string::npos)
			l.push_back(playlists[i]->get_playlist_name());

	return l;
};

List Repo::musics_playlist(string playlist_name) {
	return get_playlist(playlist_name)->get_playlist_musics();
};

List Repo::albums_playlist(string playlist_name) {
	return get_playlist(playlist_name)->get_playlist_albums();
};

List Repo::musics_album(string album_name) {
	List l;
	for(int i = 0; i < musics.size(); i++) {
		if((musics[i]->get_music_album())->get_album_name() == album_name)
			l.push_back(musics[i]->get_music_name());
	}
	return l;
};

List Repo::musics_artist(string artist_name) {
	List l;
	for(int i = 0; i < musics.size(); i++) {
		if((musics[i]->get_music_artist())->get_full_name() == artist_name)
			l.push_back(musics[i]->get_music_name());
	}
	return l;
};

List Repo::albums_artist(string artist_name) {
	List l;
	for(int i = 0; i < albums.size(); i++) {
		if((albums[i]->get_album_artist())->get_full_name() == artist_name)
			l.push_back(albums[i]->get_album_name());
	}
	return l;
};

List Repo::all_musics() {
	List l;
	for(int i = 0; i < musics.size(); i++) {
		l.push_back(musics[i]->get_music_name());
	}
	return l;
};

List Repo::all_artists() {
	List l;
	for(int i = 0; i < users.size(); i++) {
		if(users[i]->get_user_type() == Artist)
			l.push_back(users[i]->get_full_name());
	}
	return l;
};

List Repo::all_albums() {
	List l;
	for(int i = 0; i < albums.size(); i++)
		l.push_back(albums[i]->get_album_name());

	return l;
};

List Repo::all_playlists() {
	List l;
	for(int i = 0; i < playlists.size(); i++)
		l.push_back(playlists[i]->get_playlist_name());

	return l;
};

List Repo::all_musics_full_name() {
	List l;
	for(int i = 0; i < musics.size(); i++) {
		l.push_back(musics[i]->get_music_complete_name());
	}
	return l;
};

List Repo::all_artists_full_name() {
	List l;
	for(int i = 0; i < users.size(); i++) {
		if(users[i]->get_user_type() == Artist)
			l.push_back(users[i]->get_full_name());
	}
	return l;
};

List Repo::all_albums_full_name() {
	List l;
	for(int i = 0; i < albums.size(); i++)
		l.push_back(albums[i]->get_album_complete_name());

	return l;
};

List Repo::all_playlists_full_name() {
	List l;
	for(int i = 0; i < playlists.size(); i++)
		l.push_back(playlists[i]->get_playlist_complete_name());

	return l;
};

List Repo::all_playlists_of_user() {
	List l;
	for(int i = 0; i < playlists.size(); i++) {
		if((playlists[i]->get_playlist_user()->get_full_name() == curr_user->get_full_name()))
			l.push_back(playlists[i]->get_playlist_name());
	}

	return l;
};

void Repo::createPlaylist(std::string playlist_name) {
	if(is_playlist_duplicate(playlist_name)) {
		throw AlreadyExists();
	} else {
		Playlist* p = new Playlist(playlist_name, curr_user);
		playlists.push_back(p);
	}
};

bool Repo::is_playlist_duplicate(std::string playlist_name) {
	for(int i = 0; i < playlists.size(); i++) {
		if(playlists[i]->get_playlist_name() == playlist_name)
			return true;
	}
	return false;
};

void Repo::clearPlaylist(string playlist_name) {
	get_playlist(playlist_name)->clearPlaylist();
};

Music* Repo::get_music(string music_name) {
	for(int i = 0; i < musics.size(); i++) {
		if(musics[i]->get_music_name() == music_name || musics[i]->get_music_complete_name() == music_name)
			return musics[i];
	}
	throw ItemDoesNotExists();
};

Playlist* Repo::get_playlist(string playlist_name) {
	for(int i = 0; i < playlists.size(); i++) {
		if(playlists[i]->get_playlist_name() == playlist_name || playlists[i]->get_playlist_complete_name() == playlist_name)
			return playlists[i];
	}
	throw ItemDoesNotExists();
};

Album* Repo::get_album(string album_name) {
	for(int i = 0; i < albums.size(); i++) {
		if(albums[i]->get_album_name() == album_name || albums[i]->get_album_complete_name() == album_name)
			return albums[i];
	}
	throw ItemDoesNotExists();
};

User* Repo::get_artist(string artist_name) {
	for(int i = 0; i < users.size(); i++) {
		if((users[i]->get_full_name() == artist_name || users[i]->get_firstname() == artist_name || users[i]->get_lastname() == artist_name) && users[i]->get_user_type() == Artist)
			return users[i];
	}
	throw ItemDoesNotExists();
};

User* Repo::get_user(string user_name) {
	for(int i = 0; i < users.size(); i++) {
		if(users[i]->get_full_name() == user_name || users[i]->get_firstname() == user_name || users[i]->get_lastname() == user_name)
			return users[i];
	}
	throw ItemDoesNotExists();
};

bool Repo::is_curr_user_owner(Music* m) {
	if(curr_user->get_full_name() == (m->get_music_artist())->get_full_name())
		return true;
	return false;
};

void Repo::add_album_to_playlist(string album_name, string playlist_name) {
	Playlist* p = get_playlist(playlist_name);
	for(int i = 0; i < musics.size(); i++) {
		if((musics[i]->get_music_album())->get_album_name() == album_name || (musics[i]->get_music_album())->get_album_complete_name() == album_name)
			p->add_music(musics[i], curr_user);
	}
};

void Repo::add_artist_musics_to_playlist(string artist_name, string playlist_name) {
	Playlist* p = get_playlist(playlist_name);
	for(int i = 0; i < musics.size(); i++) {
		if((musics[i]->get_music_artist())->get_full_name() == artist_name)
			p->add_music(musics[i], curr_user);
	}
};

void Repo::add_playlist_music_to_playlist(string p1, string p2) {
	Playlist *p_home = get_playlist(p1);
	Playlist *p_away = get_playlist(p2);
	p_away->add_musics(p_home->get_musics() , get_curr_user());
};

void Repo::add_music_to_album(Music* m, string album_name) {
	Album* a = get_album(album_name);
	if(a->get_album_artist()->get_full_name() == curr_user->get_full_name()) {
		if(is_curr_user_owner(m)){
			m->set_album(a);
		} else
			throw NotAuthorized();
	} else 
		throw NotAuthorized();
};

void Repo::add_music_to_playlist(Music* m, string playlist_name) {
	Playlist* p = get_playlist(playlist_name);
	p->add_music(m, curr_user);
};

bool Repo::has_album(string album_name) {
	for(int i = 0; i < albums.size(); i++) {
		if(albums[i]->get_album_name() == album_name || albums[i]->get_album_complete_name() == album_name)
			return true;
	}
	return false;
};

bool Repo::has_playlist(string playlist_name) {
	for(int i = 0; i < playlists.size(); i++) {
		if(playlists[i]->get_playlist_name() == playlist_name || playlists[i]->get_playlist_complete_name() == playlist_name)
			return true;
	}
	return false;
};

bool Repo::has_music(string music_name) {
	for(int i = 0; i < musics.size(); i++) {
		if(musics[i]->get_music_name() == music_name || musics[i]->get_music_complete_name() == music_name)
			return true;
	}
	return false;
};

bool Repo::has_artist(string artist_name) {
	for(int i = 0; i < users.size(); i++) {
		if((users[i]->get_full_name() == artist_name || users[i]->get_firstname() == artist_name || users[i]->get_lastname() == artist_name) && users[i]->get_user_type() == Artist)
			return true;
	}
	return false;
};

void Repo::delete_music_from_playlists(std::string music_name) {
	Music* m = get_music(music_name);
	for(int i = 0; i < playlists.size(); i++) {	
		if(is_curr_user_owner(m))
			playlists[i]->delete_music(music_name);
		else 
			throw NotAuthorized();
	}
};
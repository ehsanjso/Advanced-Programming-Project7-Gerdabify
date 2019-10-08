#include "browser.h"

using namespace std;

Browser* Browser::instance = 0;

Browser* Browser::getInstance() {
    if (instance == 0) {
        instance = new Browser();
    }
    return instance;
};

void Browser::make_page(string type_name) {
	if(type_name == HOME) {
		Home* p = Home::getInstance(HOME);
		page = p;
	} else if(type_name == PLAYLIST) {
		Playlist_page *p = Playlist_page::getInstance(PLAYLIST);
		page = p;
	} else if(type_name == ALBUM) {
		Album_page *p = Album_page::getInstance(ALBUM);
		page = p;
	} else if(type_name == ARTIST) {
		Artist_page *p = Artist_page::getInstance(ARTIST);
		page = p;
	} else if(type_name == LIBRARY) {
		Library *p = Library::getInstance(LIBRARY);
		page = p;
	} else if(type_name == MUSIC) {
		Music_page *p = Music_page::getInstance(MUSIC);
		page = p;
	}
};

void Browser::goToHome() {
	Home* h = Home::getInstance(HOME);
	page = h;	
};

void Browser::goToPlayLists() {
	if(page->get_type() == HOME) {
		Playlists_page *p = Playlists_page::getInstance(PLAYLISTS);
		page = p;
	} else 
		throw MethodNotAvailable();
};

void Browser::goToPlayList() {
	if(page->get_type() == HOME) {
		Playlists_page *p = Playlists_page::getInstance(PLAYLISTS);
		page = p;
	} else 
		throw MethodNotAvailable();
};

void Browser::goToLibrary() {
	if(page->get_type() == HOME) {
		Library *l = Library::getInstance(LIBRARY);
		page = l;
	} else  
		throw MethodNotAvailable();
};

void Browser::goToAlbum() {
	if(page->get_type() == MUSIC) {
		Album* al = (((Music_page*)page)->get_music())->get_music_album();
		Album_page *a = Album_page::getInstance(ALBUM);
		a->set_album(al);
		page = a;
	} else 
		throw MethodNotAvailable();
};

void Browser::goToArtist() {
	if(page->get_type() == MUSIC) {
		User* us = (((Music_page*)page)->get_music())->get_music_artist();
		Artist_page *a = Artist_page::getInstance(ARTIST);
		a->set_artist(us);
		page = a;
	} else if(page->get_type() == ALBUM) {
		User* us = (((Album_page*)page)->get_album())->get_album_artist();
		Artist_page *a = Artist_page::getInstance(ARTIST);
		a->set_artist(us);
		page = a;
	} else 
		throw MethodNotAvailable();
};

void Browser::goToMusic() {

};

vector<string> Browser::list() {
	return page->list();
};

vector<string> Browser::listMusics() {
	return page->listMusics();
};

vector<string> Browser::listAlbums() {
	return page->listAlbums();
};

vector<string> Browser::listPlaylists() {
	return page->listPlaylists();
};

vector<string> Browser::listArtists() {
	return page->listArtists();
};

vector<string> Browser::listMusics_full_name() {
	return page->listMusics_full_name();
};

vector<string> Browser::listAlbums_full_name() {
	return page->listAlbums_full_name();
};

vector<string> Browser::listPlaylists_full_name() {
	return page->listPlaylists_full_name();
};

vector<string> Browser::listArtists_full_name() {
	return page->listArtists_full_name();
};

void Browser::play() {
	page->play();
};

void Browser::remove(string music_name) {
	page->remove(music_name);
};

void Browser::addTo(string s) {
	page->addTo(s);
};

void Browser::orderItem(string music_name, int new_order) {
	if(page->get_type() == PLAYLIST) {
		((Playlist_page*)page)->orderItem(music_name, new_order);
	} else
		throw MethodNotAvailable();
};

void Browser::goTo(string playlist_name) {
	Repo* r = Repo::getInstance();
	Playlist_page* p;
	if(r->has_playlist(playlist_name)) {
		p = Playlist_page::getInstance(PLAYLIST);
		p->set_playlist(r->get_playlist(playlist_name));
		page = p;
	} else 
		throw ItemDoesNotExists();
};

string Browser::getArtist() {
	page->getArtist();
};

string Browser::getAlbum() {
	if(page->get_type() == MUSIC)
		((Music_page*)page)->getAlbum();
	else 
		throw MethodNotAvailable();
};

std::string Browser::getName() {
	page->getName();
};

std::string Browser::getCompleteName() {
	page->getCompleteName();
};

void Browser::select(string s) {
	Repo* r = Repo::getInstance();
	if(r->has_music(s)) {
		Music_page *p = Music_page::getInstance(MUSIC);
		p->set_music(r->get_music(s));
		page = p;
	} else if(r->has_album(s)) {
		Album_page *p = Album_page::getInstance(ALBUM);
		p->set_album(r->get_album(s));
		page = p;
	} else if(r->has_playlist(s)) {
		Playlist_page *p = Playlist_page::getInstance(PLAYLIST);
		p->set_playlist(r->get_playlist(s));
		page = p;
	} else if(r->has_artist(s)) {
		Artist_page *p = Artist_page::getInstance(ARTIST);
		p->set_artist(r->get_artist(s));
		page = p;
	} else 
		throw ItemDoesNotExists();
};

void Browser::rate(int score) {
	page->rate(score);
};

int Browser::getRate() {
	return page->getRate();
};

int Browser::getUserRate() {
	return page->getUserRate();
};

int Browser::getCriticRate() {
	return page->getCriticRate();
};

void Browser::validate() {
	page->validate();
};
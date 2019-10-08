#include "api.hpp"
#include <iostream>

GerdabifyAPI* GerdabifyAPI::instance = 0;

GerdabifyAPI* GerdabifyAPI::getInstance() {
    if (instance == 0) {
        instance = new GerdabifyAPI();
    }
    return instance;
};

GerdabifyAPI::GerdabifyAPI() {
	Auth *a = Auth::getInstance();
	auth = a;
	Repo *r = Repo::getInstance();
	repo = r;
};

// Browser

void GerdabifyAPI::enterBrowserMode() {
	Browser* b = Browser::getInstance();
	mode = b;
};

void GerdabifyAPI::goToHome() {
	if(mode->get_type() == "browser")
		((Browser*)mode)->goToHome();
	else
		throw MethodNotAvailable();
};

void GerdabifyAPI::goToPlayList() {
	if(mode->get_type() == "browser")
		((Browser*)mode)->goToPlayList();
	else
		throw MethodNotAvailable();
};

void GerdabifyAPI::goToPlayLists() {
	if(mode->get_type() == "browser")
		((Browser*)mode)->goToPlayLists();
	else
		throw MethodNotAvailable();
};

void GerdabifyAPI::goToLibrary() {
	if(mode->get_type() == "browser")
		((Browser*)mode)->goToLibrary();
	else
		throw MethodNotAvailable();
};

void GerdabifyAPI::goToAlbum() {
	if(mode->get_type() == "browser")
		((Browser*)mode)->goToAlbum();
	else
		throw MethodNotAvailable();
};

void GerdabifyAPI::goToArtist() {
	if(mode->get_type() == "browser")
		((Browser*)mode)->goToArtist();
	else
		throw MethodNotAvailable();
};

void GerdabifyAPI::goToMusic() {
	if(mode->get_type() == "browser")
		((Browser*)mode)->goToMusic();
	else
		throw MethodNotAvailable();
};

// Auth

void GerdabifyAPI::signup(UserData data, string pass) {
	auth->signup(data.firstname, data.lastname, data.username, pass, data.userType);
};

void GerdabifyAPI::login(string user, string pass) {
	if(!(auth->login(user, pass)))
		throw InvalidCredentials();
};

void GerdabifyAPI::addMusic(string music_name, string path) {
	repo->add_music(music_name, path);
};

void GerdabifyAPI::addAlbum(string artist_name, string album_name) {
	repo->add_album(artist_name, album_name);
};

void GerdabifyAPI::validate() {
	if(mode->get_type() == "browser")
		((Browser*)mode)->validate();
	else
		throw MethodNotAvailable();
};

void GerdabifyAPI::verifyUser(string user_name) {
	(repo->get_user(user_name))->validate();
};

UserData GerdabifyAPI::getUserDetails(string username) {
	return repo->getUserDetails(username);
};

List GerdabifyAPI::search(string s) {
	return repo->search(s);
};

void GerdabifyAPI::select(string s) {
	Browser* b = Browser::getInstance();
	mode = b;
	return b->select(s);
}

List GerdabifyAPI::list() {
	return ((Browser*)mode)->list();
};

List GerdabifyAPI::listMusics() {
	if(mode->get_type() == "browser")
		return ((Browser*)mode)->listMusics();
	else
		throw MethodNotAvailable();
};

List GerdabifyAPI::listAlbums() {
	if(mode->get_type() == "browser")
		return ((Browser*)mode)->listAlbums();
	else
		throw MethodNotAvailable();
};

List GerdabifyAPI::listPlaylists() {
	if(mode->get_type() == "browser")
		return ((Browser*)mode)->listPlaylists();
	else
		throw MethodNotAvailable();
};

List GerdabifyAPI::listArtists() {
	if(mode->get_type() == "browser")
		return ((Browser*)mode)->listArtists();
	else
		throw MethodNotAvailable();
};

List GerdabifyAPI::listMusics_full_name() {
	if(mode->get_type() == "browser")
		return ((Browser*)mode)->listMusics_full_name();
	else
		throw MethodNotAvailable();
};

List GerdabifyAPI::listAlbums_full_name() {
	if(mode->get_type() == "browser")
		return ((Browser*)mode)->listAlbums_full_name();
	else
		throw MethodNotAvailable();
};

List GerdabifyAPI::listPlaylists_full_name() {
	if(mode->get_type() == "browser")
		return ((Browser*)mode)->listPlaylists_full_name();
	else
		throw MethodNotAvailable();
};

List GerdabifyAPI::listArtists_full_name() {
	if(mode->get_type() == "browser")
		return ((Browser*)mode)->listArtists_full_name();
	else
		throw MethodNotAvailable();
};

// PlayList

void GerdabifyAPI::play() {
	if(mode->get_type() == "browser") {
		((Browser*)mode)->play();
		enterPlayMode();
	} else if(mode->get_type() == "player")
		((Player*)mode)->play();
	else
		throw MethodNotAvailable();
};

void GerdabifyAPI::addTo(string s) {
	if(mode->get_type() == "browser")
		((Browser*)mode)->addTo(s);
	else
		throw MethodNotAvailable();
};

void GerdabifyAPI::goTo(string playlist_name) {
	Browser* b = Browser::getInstance();
	b->goTo(playlist_name);
	mode = b;
};

void GerdabifyAPI::createPlaylist(string playlist_name) {
	repo->createPlaylist(playlist_name);
};

void GerdabifyAPI::clearPlaylist(string playlist_name) {
	repo->clearPlaylist(playlist_name);
};

void GerdabifyAPI::remove(string music_name) {
	if(mode->get_type() == "browser")
		((Browser*)mode)->remove(music_name);
	else
		throw MethodNotAvailable();
};

void GerdabifyAPI::orderItem(string music_name, int new_order) {
	if(mode->get_type() == "browser")
		((Browser*)mode)->orderItem(music_name, new_order);
	else
		throw MethodNotAvailable();
};

void GerdabifyAPI::rate(int score) {
	if(mode->get_type() == "browser")
		((Browser*)mode)->rate(score);
	else
		throw MethodNotAvailable();
};


// Information

string GerdabifyAPI::getArtist() {
	if(mode->get_type() == "browser")
		((Browser*)mode)->getArtist();
	else
		throw MethodNotAvailable();
};

string GerdabifyAPI::getAlbum() {
	if(mode->get_type() == "browser")
		((Browser*)mode)->getAlbum();
	else
		throw MethodNotAvailable();
};

int GerdabifyAPI::getLength() {

};

string GerdabifyAPI::getName() {
	if(mode->get_type() == "browser")
		((Browser*)mode)->getName();
	else
		throw MethodNotAvailable();
};

string GerdabifyAPI::getCompleteName() {
	if(mode->get_type() == "browser")
		((Browser*)mode)->getCompleteName();
	else
		throw MethodNotAvailable();
};

int GerdabifyAPI::getRate() {
	if(mode->get_type() == "browser")
		((Browser*)mode)->getRate();
	else
		throw MethodNotAvailable();
};

int GerdabifyAPI::getUserRate() {
	if(mode->get_type() == "browser")
		((Browser*)mode)->getUserRate();
	else
		throw MethodNotAvailable();
};

int GerdabifyAPI::getCriticRate() {
	if(mode->get_type() == "browser")
		((Browser*)mode)->getCriticRate();
	else
		throw MethodNotAvailable();
};

// Player

void GerdabifyAPI::enterPlayMode() {
	Player* p = Player::getInstance();
	p->set_player_playlist(repo->get_playlist("queue"));
	mode = p;
};

void GerdabifyAPI::next() {
	if(mode->get_type() == "player")
		((Player*)mode)->next();
	else
		throw MethodNotAvailable();
};

void GerdabifyAPI::previous() {
	if(mode->get_type() == "player")
		((Player*)mode)->next();
	else
		throw MethodNotAvailable();
};

void GerdabifyAPI::pause() {
	if(mode->get_type() == "player")
		((Player*)mode)->pause();
	else
		throw MethodNotAvailable();
};

void GerdabifyAPI::seek(int min, int sec) {
	if(mode->get_type() == "player")
		((Player*)mode)->seek(min, sec);
	else
		throw MethodNotAvailable();
};

void GerdabifyAPI::shuffle() {
	if(mode->get_type() == "player")
		((Player*)mode)->shuffle();
	else
		throw MethodNotAvailable();
};

void GerdabifyAPI::repeatOne() {
	if(mode->get_type() == "player")
		((Player*)mode)->repeatOne();
	else
		throw MethodNotAvailable();
};

void GerdabifyAPI::repeat() {
	if(mode->get_type() == "player")
		((Player*)mode)->repeat();
	else
		throw MethodNotAvailable();
};

GerdabPlayer* GerdabifyAPI::get_player() {
	if(mode->get_type() == "player")
		return ((Player*)mode)->get_player();
	else
		throw MethodNotAvailable();
};
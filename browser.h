#include "mode.h"
#include "error.h"
#include "p_playlist.h"
#include "p_playlists.h"
#include "library.h"
#include "p_music.h"
#include "p_album.h"
#include "p_artist.h"
#include "home.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

#define HOME "home"
#define PLAYLISTS "playlists"
#define PLAYLIST "playlist"
#define ALBUM "album"
#define ARTIST "artist"
#define LIBRARY "library"
#define MUSIC "music"

#ifndef BROWSER_H
#define BROWSER_H

class Browser : public Mode {
public:
    static Browser* getInstance();
    void make_page(std::string type_name);
    std::string get_type() { return "browser"; }
    void goToHome();
    void goToPlayLists();
    void goToPlayList();
    void goToLibrary();
    void goToAlbum();
    void goToArtist();
    void goToMusic(); // i add
    std::vector<std::string> list();
    std::vector<std::string> listMusics();
    std::vector<std::string> listAlbums();
    std::vector<std::string> listPlaylists();
    std::vector<std::string> listArtists();
    std::vector<std::string> listMusics_full_name();
    std::vector<std::string> listAlbums_full_name();
    std::vector<std::string> listPlaylists_full_name();
    std::vector<std::string> listArtists_full_name();
    void play();
    void remove(std::string);
    void addTo(std::string);
    void orderItem(std::string, int);
    void goTo(std::string);
    std::string getArtist();
    std::string getAlbum();
    std::string getName();
    std::string getCompleteName();
    void select(std::string s);
    void rate(int);
    int getRate();
    int getUserRate();
    int getCriticRate();
    void validate();
private:
	static Browser* instance;
    Browser() {}
    Page* page;
};

#endif
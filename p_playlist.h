#include "page.h"
#include "playlist.h"

#ifndef P_PLAYLIST_H
#define P_PLAYLIST_H

class Playlist_page : public Page {
public:
    static Playlist_page* getInstance(std::string s);
    void set_playlist(Playlist* p) { playlist = p; }
    std::vector<std::string> list();
    std::vector<std::string> listMusics();
    std::vector<std::string> listAlbums();
    std::vector<std::string> listPlaylists();
    std::vector<std::string> listArtists() { throw MethodNotAvailable(); }
    std::vector<std::string> listMusics_full_name() { throw MethodNotAvailable(); }
    std::vector<std::string> listAlbums_full_name() { throw MethodNotAvailable(); }
    std::vector<std::string> listPlaylists_full_name();
    std::vector<std::string> listArtists_full_name() { throw MethodNotAvailable(); }
    void remove(std::string);
    void orderItem(std::string, int);
    void addTo(std::string) { throw MethodNotAvailable(); }
    std::string getArtist() { throw MethodNotAvailable(); }
    std::string getName() { return playlist->get_playlist_name(); }
    void play();
    std::string getCompleteName() { playlist->get_playlist_complete_name(); }
    void rate(int) { throw MethodNotAvailable(); }
    int getRate() { throw MethodNotAvailable(); }
    int getUserRate() { throw MethodNotAvailable(); }
    int getCriticRate() { throw MethodNotAvailable(); }
    void validate() { throw MethodNotAvailable(); }
private:
	static Playlist_page* instance;
    Playlist_page(std::string s) : Page(s) { 
    	Repo* r = Repo::getInstance();
    	repo = r;
    }
    Repo* repo;
    Playlist* playlist;
};

#endif
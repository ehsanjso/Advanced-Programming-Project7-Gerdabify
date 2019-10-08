#include "page.h"
#include "playlist.h"
#include <vector>

#ifndef P_PLAYLISTS_H
#define P_PLAYLISTS_H

class Playlists_page : public Page {
public:
    static Playlists_page* getInstance(std::string s);
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
    void orderItem(std::string, int) { throw MethodNotAvailable(); }
    void addTo(std::string) { throw MethodNotAvailable(); }
    std::string getArtist() { throw MethodNotAvailable(); }
    std::string getName() { throw MethodNotAvailable(); }
    void play() { throw MethodNotAvailable(); }
    std::string getCompleteName() { throw MethodNotAvailable(); }
    void rate(int) { throw MethodNotAvailable(); }
    int getRate() { throw MethodNotAvailable(); }
    int getUserRate() { throw MethodNotAvailable(); }
    int getCriticRate() { throw MethodNotAvailable(); }
    void validate() { throw MethodNotAvailable(); }
private:
	static Playlists_page* instance;
    Playlists_page(std::string s) : Page(s) { 
    	Repo* r = Repo::getInstance();
    	repo = r;
    }
    Repo* repo;
};

#endif
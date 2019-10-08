#include "page.h"

#ifndef LIBRARY_H
#define LIBRARY_H

class Library : public Page {
public:
    static Library* getInstance(std::string s);
    std::vector<std::string> list();
    std::vector<std::string> listMusics();
    std::vector<std::string> listAlbums();
    std::vector<std::string> listArtists();
    std::vector<std::string> listPlaylists() { throw MethodNotAvailable(); }
    std::vector<std::string> listMusics_full_name();
    std::vector<std::string> listAlbums_full_name();
    std::vector<std::string> listArtists_full_name();
    std::vector<std::string> listPlaylists_full_name() { throw MethodNotAvailable(); }
    void remove(std::string) {}
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
	static Library* instance;
    Library(std::string s) : Page(s) {
    	Repo* r = Repo::getInstance();
    	repo = r;
    }
    Repo* repo;
};

#endif
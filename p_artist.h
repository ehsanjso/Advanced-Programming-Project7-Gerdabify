#include "page.h"
#include "user.h"

#ifndef ARTSITPAGE_H
#define ARTSITPAGE_H

class Artist_page : public Page {
public:
    static Artist_page* getInstance(std::string s);
    void set_artist(User* u) { artist = u; }
    std::vector<std::string> list();
    std::vector<std::string> listMusics();
    std::vector<std::string> listAlbums();
    std::vector<std::string> listPlaylists() { throw MethodNotAvailable(); }
    std::vector<std::string> listArtists() { throw MethodNotAvailable(); }
    std::vector<std::string> listMusics_full_name() { throw MethodNotAvailable(); }
    std::vector<std::string> listAlbums_full_name() { throw MethodNotAvailable(); }
    std::vector<std::string> listPlaylists_full_name() { throw MethodNotAvailable(); }
    std::vector<std::string> listArtists_full_name() { throw MethodNotAvailable(); }
    void remove(std::string) {}
    void addTo(std::string) { throw MethodNotAvailable(); }
    std::string getArtist() { throw MethodNotAvailable(); }
    std::string getName() { return artist->get_full_name(); }
    void play();
    std::string getCompleteName() { artist->get_full_name(); }
    void rate(int);
    int getRate();
    int getUserRate();
    int getCriticRate();
    void validate();
private:
	static Artist_page* instance;
    Artist_page(std::string s) : Page(s) {
    	Repo* r = Repo::getInstance();
    	repo = r;
    }
    Repo* repo;
    User* artist;
};

#endif
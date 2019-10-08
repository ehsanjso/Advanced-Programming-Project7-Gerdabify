#include "page.h"
#include "album.h"

#ifndef ALBUMPAGE_H
#define ALBUMPAGE_H

class Album_page : public Page {
public:
    static Album_page* getInstance(std::string s);
    Album* get_album() { return album; }
    void set_album(Album* a) { album = a; }
    std::vector<std::string> list();
    std::vector<std::string> listMusics();
    std::vector<std::string> listAlbums() {}
    std::vector<std::string> listPlaylists() { throw MethodNotAvailable(); }
    std::vector<std::string> listArtists() { throw MethodNotAvailable(); }
    std::vector<std::string> listMusics_full_name() { throw MethodNotAvailable(); }
    std::vector<std::string> listAlbums_full_name() { throw MethodNotAvailable(); }
    std::vector<std::string> listPlaylists_full_name() { throw MethodNotAvailable(); }
    std::vector<std::string> listArtists_full_name() { throw MethodNotAvailable(); }
    void remove(std::string);
    void addTo(std::string);
    std::string getArtist();
    std::string getName() { return album->get_album_name(); }
    void play();
    std::string getCompleteName() { album->get_album_complete_name(); }
    void rate(int);
    int getRate();
    int getUserRate();
    int getCriticRate();
    void validate();
private:
	static Album_page* instance;
    Album_page(std::string s) : Page(s) {
    	Repo* r = Repo::getInstance();
    	repo = r;
    }
    Repo* repo;
    Album* album;
};

#endif
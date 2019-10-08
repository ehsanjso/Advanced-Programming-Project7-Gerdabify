#include "page.h"
#include "music.h"

#ifndef P_MUSIC_H
#define P_MUSIC_H

class Music_page : public Page {
public:
    static Music_page* getInstance(std::string s);
    void set_music(Music* m) { music = m; }
    Music* get_music() { return music; }
    std::vector<std::string> list() { throw MethodNotAvailable(); }
    std::vector<std::string> listMusics() { throw MethodNotAvailable(); }
    std::vector<std::string> listAlbums() { throw MethodNotAvailable(); }
    std::vector<std::string> listPlaylists() { throw MethodNotAvailable(); }
    std::vector<std::string> listArtists() { throw MethodNotAvailable(); }
    std::vector<std::string> listMusics_full_name() { throw MethodNotAvailable(); }
    std::vector<std::string> listAlbums_full_name() { throw MethodNotAvailable(); }
    std::vector<std::string> listPlaylists_full_name() { throw MethodNotAvailable(); }
    std::vector<std::string> listArtists_full_name() { throw MethodNotAvailable(); }
    void remove(std::string) { throw MethodNotAvailable(); }
    void orderItem(std::string, int) { throw MethodNotAvailable(); }
    void addTo(std::string);
    std::string getArtist();
    std::string getAlbum();
    std::string getName() { return music->get_music_name(); }
    void play();
    std::string getCompleteName() { music->get_music_complete_name(); }
    void rate(int);
    int getRate();
    int getUserRate();
    int getCriticRate();
    void validate();
private:
	static Music_page* instance;
    Music_page(std::string s) : Page(s) { 
    	Repo* r = Repo::getInstance();
    	repo = r;
    }
    Repo* repo;
    Music* music;
};

#endif
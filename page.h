#include <string>
#include <vector>
#include "repo.h"

#ifndef PAGE_H
#define PAGE_H

class Page {
public:
	Page(std::string s) : type(s) {}
	std::string get_type() { return type; }
	virtual std::vector<std::string> list() = 0;
	virtual std::vector<std::string> listMusics() = 0;
	virtual std::vector<std::string> listAlbums() = 0;
	virtual std::vector<std::string> listPlaylists() = 0;
	virtual std::vector<std::string> listArtists() = 0;
	virtual std::vector<std::string> listMusics_full_name() = 0;
	virtual std::vector<std::string> listAlbums_full_name() = 0;
	virtual std::vector<std::string> listPlaylists_full_name() = 0;
	virtual std::vector<std::string> listArtists_full_name() = 0;
	virtual void remove(std::string) = 0;
	virtual void addTo(std::string) = 0;
	virtual std::string getArtist() = 0;
	virtual std::string getName() = 0;
	virtual void play() = 0;
	virtual std::string getCompleteName() = 0;
	virtual void rate(int) = 0;
	virtual int getRate() = 0;
    virtual int getUserRate() = 0;
    virtual int getCriticRate() = 0;
    virtual void validate() = 0;
    //static Page* getInstance();
private:
	//static Page* instance;
    //Page() {}
    std::string type;
};

#endif
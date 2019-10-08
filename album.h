#include "user.h"
#include "rate.h"
#include <string>
#include <vector>

#ifndef ALBUM_H
#define ALBUM_H

class Album {
public:
	Album(std::string name, User* u) : album_name(name), artist(u) { validated = false; }
	std::string get_album_name() { return album_name; }
	User* get_album_artist() { return artist; }
	Rate* get_album_rate() { return rate; }
	std::string get_album_complete_name();
	void validate() { validated = true; }
private:
	User* artist;
	Rate* rate;
	std::string album_name;
	bool validated;
};

#endif
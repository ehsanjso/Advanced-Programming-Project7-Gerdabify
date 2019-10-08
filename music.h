#include "album.h"
#include "rate.h"
#include <string>
#include <vector>

#ifndef MUSIC_H
#define MUSIC_H

class User;

class Music {
public:
	Music(std::string name, std::string p, User* u) : artist(u), music_name(name), path(p) { validated = false; } 
	std::string get_music_name() { return music_name; }
	std::string get_music_path() { return path; }
	void delete_from_album();
	Album* get_music_album() { return album; }
	User* get_music_artist() { return artist; }
	Rate* get_music_rate() { return rate; }
	std::string get_music_complete_name();
	void set_album(Album* a) { album = a; }
	void validate() { validated = true; }
private:
	Album* album;
	User* artist;
	Rate* rate;
	std::string music_name;
	std::string path;
	bool validated;
};

#endif
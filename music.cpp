#include "music.h"

using namespace std;

void Music::delete_from_album() {
	album = NULL;
};

std::string Music::get_music_complete_name() { 
	if(album != NULL)
		return album->get_album_complete_name() + '-' + music_name;
	else 
		return get_music_name();
};

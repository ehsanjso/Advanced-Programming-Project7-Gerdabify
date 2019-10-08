#include "album.h"

using namespace std;

std::string Album::get_album_complete_name() { 
	if(artist != NULL)
		return artist->get_full_name() + '-' + album_name;
	else 
		return get_album_name();
};
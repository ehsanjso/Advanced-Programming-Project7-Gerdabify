#include "home.h"

using namespace std;

Home* Home::instance = 0;

Home* Home::getInstance(string s) {
    if (instance == 0) {
        instance = new Home(s);
    }
    return instance;
};

vector<string> Home::list() {
	vector<string> l;
	l.push_back("library");
	l.push_back("playlists");
	return l;
};
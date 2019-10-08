#include "auth.h"
#include <iostream>

using namespace std;

Auth* Auth::instance = 0;

Auth* Auth::getInstance() {
    if (instance == 0) {
        instance = new Auth();
    }
    return instance;
};

Auth::Auth() {
	Repo* r = Repo::getInstance();
	repo = r;
	signup("admin","admin","admin","admin", Admin);
	repo->set_user(NULL);
};

void Auth::signup(string first, string last, string user, string pass, UserType type) {
	if(!repo->is_user_duplicate(user)) {
		User* u = new User(first, last, user, pass, type);
		repo->add_user(u);
	} else 
		throw AlreadyExists();
};

bool Auth::login(string user, string pass) {
	return repo->auth_user(user, pass);
};
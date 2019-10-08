#include <string>
#include <vector>
#include "user.h"
#include "error.h"
#include "repo.h"

#ifndef AUTH_H
#define AUTH_H

class Auth {
public:
	static Auth* getInstance();
    void signup(std::string first, std::string last, std::string user, std::string pass, UserType type = Normal);
    bool login(std::string user, std::string pass);
    User* get_curr_user() { return repo->get_curr_user(); }
private:
	static Auth* instance;
    Auth();
	Repo* repo;
};

#endif
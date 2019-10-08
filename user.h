#include <string>
#include <vector>
#include "error.h"

#ifndef USER_H
#define USER_H

enum UserType {Admin, Artist, Editor, Normal};

struct UserData
{
    std::string firstname;
    std::string lastname;
    std::string username;
    UserType userType;
};

class Rate;

class User {
public:
	User(std::string first, std::string last, std::string user, std::string pass, UserType type = Normal) :
	 firstname(first), lastname(last), username(user), password(pass), userType(type) { validated = false; }
	std::string get_username() { return username; }
	std::string get_firstname() { return firstname; }
	std::string get_lastname() { return lastname; }
	UserType get_user_type() { return userType; }
	Rate* get_artist_rate() { return rate; }
	void validate() { validated = true; }
	bool authenticate(std::string user, std::string pass);
	// void validate(User* u);
	// void validate(Album* a);
	// void validate(Music* m);
	UserData getUserDetails();
	std::string get_full_name() { return firstname + ' ' + lastname; }
private:
	std::string firstname;
    std::string lastname;
    std::string username;
    std::string password;
    UserType userType;
    bool validated;
    Rate* rate;
};

#endif
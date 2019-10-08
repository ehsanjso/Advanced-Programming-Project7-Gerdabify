#include "user.h"

using namespace std;

bool User::authenticate(string user, string pass) {
	if(user == username && pass == password) 
		return true;
	return false;
};

// void User::validate(User* u) {
// 	if(userType == Admin) {

// 	} else {
// 		throw NotAuthorized();
// 	}
// };

// void User::validate(Album* a) {
// 	if(userType == Admin) {
		
// 	} else {
// 		throw NotAuthorized();
// 	}
// };

// void User::validate(Music* m) {
// 	if(userType == Admin) {
		
// 	} else {
// 		throw NotAuthorized();
// 	}
// };

UserData User::getUserDetails() {
	UserData u;
	u.firstname = firstname;
	u.lastname = lastname;
	u.username = username;
	u.userType = userType;
	return u;
};
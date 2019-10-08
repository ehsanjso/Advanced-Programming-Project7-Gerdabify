#include "rate.h"

using namespace std;

void Rate::add_rate(int score, User* u) {
	if(score < 0 || score > 10)
		throw InvalidArguments();
	else {
		rates.push_back(score);
		users.push_back(u);
	}
};

int Rate::getRate(User* u) {
	for(int i = 0; i < users.size(); i++) {
		if(users[i]->get_full_name() == u->get_full_name())
			return rates[i];
	}
	throw ItemDoesNotExists();
};

int Rate::getUserRate() {
	int sum = 0;
	int n = 0;
	for(int i = 0; i < users.size(); i++) {
		if(users[i]->get_user_type() == Normal || users[i]->get_user_type() == Artist)  {
			sum += rates[i];
			n++;
		}
	}
	return (sum / n);
};

int Rate::getCriticRate() {
	int sum = 0;
	int n = 0;
	for(int i = 0; i < users.size(); i++) {
		if(users[i]->get_user_type() == Editor)  {
			sum += rates[i];
			n++;
		}
	}
	return (sum / n);
};
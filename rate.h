#include <string>
#include <vector>
#include "user.h"
#include "error.h"

#ifndef RATE_H
#define RATE_H

class Rate {
public:
	Rate() {}
	void add_rate(int score, User* u);
	int getRate(User* u);
	int getUserRate();
	int getCriticRate();
private:
	std::vector<User*> users;
	std::vector<int> rates;
};

#endif
#include "mode.h"

#ifndef MANAGER_H
#define MANAGER_H

class Manager{
public:
    static Manager* getInstance();
private:
	static Manager* instance;
    Manager() {}
};

#endif
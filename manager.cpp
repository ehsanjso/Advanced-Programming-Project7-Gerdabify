#include "manager.h"

using namespace std;

Manager* Manager::instance = 0;

Manager* Manager::getInstance() {
    if (instance == 0) {
        instance = new Manager();
    }
    return instance;
}
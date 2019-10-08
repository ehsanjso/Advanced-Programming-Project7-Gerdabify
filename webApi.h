#ifndef WEBAPI_H
#define WEBAPI_H

#include "mainHandler.h"
#include "loginHandler.h"
#include "signupHandler.h"
#include "searchHandler.h"
#include "musicHandler.h"
#include "albumHandler.h"
#include "playlistsHandler.h"
#include "playlistHandlerPost.h"
#include "artistHandler.h"
#include "api.hpp"

class WebApi {
public:
	static WebApi* getInstance();
private:
	static WebApi* instance;
    WebApi();
};

#endif
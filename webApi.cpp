#include "webApi.h"

using namespace std;

WebApi* WebApi::instance = 0;

WebApi* WebApi::getInstance() {
    if (instance == 0) {
        instance = new WebApi();
    }
    return instance;
};

WebApi::WebApi() { 
	try {
        Server server;
        RequestHandler* mainPage = new mainHandler();
        RequestHandler* loginPage = loginHandler::getInstance();
        RequestHandler* signupPage = new signupHandler();
        RequestHandler* searchPage = new searchHandler();
        RequestHandler* musicPage = new musicHandler();
        RequestHandler* albumPage = new albumHandler();
        RequestHandler* playlistsPage = new playlistsHandler();
        RequestHandler* playlistsPagePost = new playlistsHandlerPost();
        RequestHandler* artistPage = new artistHandler();
        server.get("/", mainPage);
        server.post("/login", loginPage);
        server.post("/signup", signupPage);
        server.post("/search", searchPage);
        server.get("/musics", musicPage);
        server.get("/albums", albumPage);
        server.get("/artists", artistPage);
        server.get("/playlists", playlistsPage);
        server.post("/playlists", playlistsPagePost);
        cout << "Listening on port 5000" << endl;
        server.start(5000);
    } catch(Exception e) {
        cerr << "WebServer: " << e.getMessage() << endl;
    }
};
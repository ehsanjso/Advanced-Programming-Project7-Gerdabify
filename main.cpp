#include <iostream>
#include <cstdlib>
#include "api.hpp"
#include "webApi.h"
#include "player.h"

using namespace std;

int main() {
	// string m1 = "examples/beat.wav";
 //  	string m2 = "examples/beat.wav";
 //  	string m3 = "examples/beat.wav";
 //  	// string m2 = "examples/book.wav";

 //  	vector<string> queue;
 //  	queue.push_back(m1);
 //  	queue.push_back(m2);
 //  	queue.push_back(m3);
 //  	GerdabPlayer* player = new GerdabPlayer();

 // 	player->setQueue(queue);
 // 	player->setRepeat(0);

 // 	char c;
 //  	while (1) {
 //  		std::cin>>c;
 //   		if(c == 'p'){
 //      		player->play();
 //    	}
 //    	else if(c == 's')
 //      		player->stop();
 //    	else if(c == 'r')
 //      		player->resume();
 //    	else if(c == 'd')
 //      		player->pause();
 //    	else if(c == 'n')
 //      		player->setMusic("examples/book.wav");
 //    	else
 //      		player->pause();
 //  	}

	GerdabifyAPI* g = GerdabifyAPI::getInstance();
	g->enterBrowserMode();
	g->goToHome();
	g->goToPlayList();
	g->signup({"ehsan", "ehsan", "ehsan", Artist}, "admin");
	g->login("ehsan", "admin");
	g->addMusic("book.wav", "examples/");
	g->addMusic("beat.wav", "examples/");
	g->addMusic("amsadasd.wav", "examples/");
	g->addMusic("qef.wav", "examples/");
	g->addMusic("fsbvdfb.wav", "examples/");
	g->addMusic("trhbnr.wav", "examples/");
	g->createPlaylist("mmmmmm");
	g->createPlaylist("eeeeeee");
	g->createPlaylist("ssss");
	Music_page *m = Music_page::getInstance("music");
	Repo *r = Repo::getInstance();
	m->set_music(r->get_music("beat.wav"));
	m->addTo("queue");
	m->set_music(r->get_music("book.wav"));
	m->addTo("queue");
	//cout << (r->get_playlist("queue")->get_playlist_musics_for_player())[0] << endl;
	g->enterPlayMode();
	//g->play();
	WebApi* w = WebApi::getInstance();
	g->play();
	// GerdabPlayer* p = g.get_player();
	// p->setQueue(queue);
	// p->setRepeat(0);
	// p->play();
	// g.goToLibrary();
	// g.goToArtist();
	// g.goToAlbum();
	// g.login("admin", "admin");
	// g.signup({"ehsan", "ehsan", "ehsan", Artist}, "admin");
	// g.login("ehsan", "admin");
	// g.addMusic("aaaa", "aaaaaaa");
	// g.signup({"mamali", "admin", "mammad", Artist}, "admin");
	// g.login("mammad", "admin");
	// g.addMusic("mmm", "mnmnmn");
	// g.addAlbum("mammad", "eshge man");
	// g.createPlaylist("myPlaylist");
	// cout << g.getUserDetails("admin").firstname << endl;
	// cout << g.search("admin")[0] << endl;
	// cout << g.list()[1] << endl;
	// g.goToMusic();
	// Music_page *m = Music_page::getInstance("music");
	// Repo *r = Repo::getInstance();
	// m->set_music(r->get_music("aaaa"));
	// m->addTo("queue");
	// g.goTo("myPlaylist");
	// g.goTo("queue");
	// cout << g.getName() << endl;

	return 0;
}
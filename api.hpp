#ifndef GERDABIFYAPI_H
#define GERDABIFYAPI_H

#include "mode.h"
#include "auth.h"
#include "browser.h"
#include "player.h"
#include "repo.h"
#include <vector>
#include <string>

#include "player.h"

using namespace std;

// class ItemDoesNotExists; // 4
// class NotAuthorized; // 3
// class MethodNotAvailable; // 5
// class InvalidArguments; // 0
// class InvalidCredentials; // 1
// class AlreadyExists; // 9

class GerdabifyAPI
{
public:
    static GerdabifyAPI* getInstance();
    void enterBrowserMode();
    void goToHome();
    void goToPlayList();
    void goToPlayLists();
    void goToLibrary();
    void goToAlbum();
    void goToArtist();
    void goToMusic(); // i add
    List search(string);
    void select(string);
    List list();
    List listMusics();
    List listAlbums();
    List listPlaylists();
    List listArtists();
    List listMusics_full_name();
    List listAlbums_full_name();
    List listPlaylists_full_name();
    List listArtists_full_name();
    void play();
    void addTo(string);
    void goTo(string);
    void createPlaylist(string);
    void clearPlaylist(string);
    void remove(string);
    void orderItem(string, int);
    void rate(int);
    string getArtist();
    string getAlbum();
    int getLength();
    string getName();
    string getCompleteName();
    int getRate();
    int getUserRate();
    int getCriticRate();
    void enterPlayMode();
    void next();
    void previous();
    void pause();
    void seek(int, int);
    void shuffle();
    void repeatOne();
    void repeat();
    void signup(UserData, string);
    void login(string, string);
    void addMusic(string, string);
    void addAlbum(string, string);
    void validate();
    UserData getUserDetails(string);
    void verifyUser(string);

    GerdabPlayer* get_player();
private:
    static GerdabifyAPI* instance;
    GerdabifyAPI();
    Mode* mode;
    Auth* auth;
    Repo* repo;
};
#endif
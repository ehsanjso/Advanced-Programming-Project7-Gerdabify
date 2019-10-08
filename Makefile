#declare the variable
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
		HEAD := \"sdlheaders/mac.hpp\"
  	CCFLAGS= -framework SDL2_mixer
else
		HEAD := \"sdlheaders/linux.hpp\"
		CCFLAGS += -l SDL2_mixer
endif

CC=g++

CFLAGS=-c

all: output.o head

output.o: page.o home.o p_artist.o p_album.o library.o p_playlist.o p_playlists.o p_music.o manager.o player.o browser.o mode.o user.o auth.o music.o album.o playlist.o rate.o repo.o gerdab.o api.o gerdabServer.o web++.o webApi.o main.o
	  	$(CC) page.o home.o p_artist.o p_album.o library.o p_playlist.o p_playlists.o p_music.o manager.o player.o browser.o mode.o user.o auth.o music.o album.o playlist.o rate.o repo.o gerdab.o api.o gerdabServer.o web++.o webApi.o main.o $(CCFLAGS) -o output.o

main.o: main.cpp api.o
		$(CC) $(CFLAGS) main.cpp

api.o: api.cpp api.hpp mode.o auth.o browser.o player.o repo.o
		$(CC) $(CFLAGS) api.cpp		

auth.o: auth.cpp auth.h user.o repo.o
		$(CC) $(CFLAGS) auth.cpp

user.o: user.cpp user.h
		$(CC) $(CFLAGS) user.cpp

mode.o: mode.cpp mode.h
		$(CC) $(CFLAGS) mode.cpp

browser.o: browser.cpp browser.h mode.o home.o p_playlist.o p_playlists.o library.o p_album.o p_artist.o p_music.o 
		$(CC) $(CFLAGS) browser.cpp

player.o: player.cpp player.h playlist.o gerdab.o
		$(CC) $(CFLAGS) player.cpp

manager.o: manager.cpp manager.h
		$(CC) $(CFLAGS) manager.cpp

repo.o: repo.cpp repo.h album.o music.o playlist.o user.o
		$(CC) $(CFLAGS) repo.cpp

rate.o: rate.cpp rate.h
		$(CC) $(CFLAGS) rate.cpp

album.o: album.cpp album.h user.o rate.o
		$(CC) $(CFLAGS) album.cpp

music.o: music.cpp music.h album.o rate.o
		$(CC) $(CFLAGS) music.cpp

playlist.o: playlist.cpp playlist.h music.o album.o user.o
		$(CC) $(CFLAGS) playlist.cpp

page.o: page.cpp page.h repo.h
		$(CC) $(CFLAGS) page.cpp

home.o: home.cpp home.h page.o
		$(CC) $(CFLAGS) home.cpp

p_playlist.o: p_playlist.cpp p_playlist.h page.o playlist.o
		$(CC) $(CFLAGS) p_playlist.cpp

p_playlists.o: p_playlists.cpp p_playlists.h page.o playlist.o
		$(CC) $(CFLAGS) p_playlists.cpp

library.o: library.cpp library.h page.o
		$(CC) $(CFLAGS) library.cpp

p_album.o: p_album.cpp p_album.h page.o album.o
		$(CC) $(CFLAGS) p_album.cpp

p_artist.o: p_artist.cpp p_artist.h page.o user.o
		$(CC) $(CFLAGS) p_artist.cpp

p_music.o: p_music.cpp p_music.h page.o music.o
		$(CC) $(CFLAGS) p_music.cpp

gerdab.o: gerdabPlayer.cpp
		g++ -std=c++11 -c gerdabPlayer.cpp -o gerdab.o

gerdabServer.o: gerdabServer.cpp
		g++ -std=c++11 -c gerdabServer.cpp -o gerdabServer.o

web++.o: web++.cpp
		g++ -std=c++11 -c web++.cpp -o web++.o

webApi.o: webApi.cpp webApi.h gerdabServer.o loginHandler.h mainHandler.h musicHandler.h signupHandler.h searchHandler.h albumHandler.h playlistsHandler.h playlistHandlerPost.h artistHandler.h
		$(CC) $(CFLAGS) webApi.cpp

head:
		echo "#include "$(HEAD) > sdlHeaders.hpp

clean:
		rm -rf *o output.o

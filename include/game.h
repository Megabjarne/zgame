#ifndef _game_h
#define _game_h

#include <map.h>
#include <player.h>
#include <graphics.h>
#include <commands.h>
#include <list>

#include <string>

class Command;

class Game {
private:
	bool running = false;
	std::list<Command*> commands; // holds all commands known to the game

public:
	Game();
	
	Map map;
	Player player;
	
	void run();
	void stop();
	void process_input();
};
extern Game game;


#endif


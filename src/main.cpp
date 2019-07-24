#include <unistd.h>
#include <iostream>
#include <string>
#include <list>

#include <graphics.h>
#include <game.h>

using std::string;
using std::list;
using std::cout;


int main(){
	init_graphics();
	
	game.player.set_room(game.map.get_room(1));
	game.run();
	
	usleep(1 * 1000000);
	
	stop_graphics();
	return 0;
}


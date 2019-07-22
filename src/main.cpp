#include <unistd.h>
#include <iostream>
#include <string>
#include <list>

#include <graphics.h>

#include <game.h>
#include <room.h>
#include <link.h>

using std::string;
using std::list;
using std::cout;

ncgui::box *guiroot;

void setup_gui(){
	// init ncurses
	initscr();
	noecho();
	
	// build initial gui stage
	guiroot = new ncgui::box("root", "zgame");
	guiroot->setelement(new ncgui::split("topsplit", ncgui::VERTICAL, ncgui::partsize(), ncgui::partsize(20)));
	
	guiroot->agetelement<ncgui::split>("topsplit")->setelement(0, new ncgui::textconsole("worldconsole"));
	guiroot->agetelement<ncgui::split>("topsplit")->setelement(1, new ncgui::textconsole("rightshit"));
	
	guiroot->maximize();
	guiroot->redraw();
}

void cleanup_gui(){
	endwin();
}

int main(){
	setup_gui();
	
	Room* r = game.map.get_player_room();
	r->describe();
	usleep(10000000);
	
	cleanup_gui();
	return 0;
}


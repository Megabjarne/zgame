
#include <graphics.h>

void build_gui();

ncgui::box *guiroot;

void init_graphics(){
	initscr(); // init ncurses
	noecho(); // disable echoing of input
	curs_set(0); // make cursor invisible
	
	build_gui();
}

void build_gui(){
	// build initial gui stage
	guiroot = new ncgui::box("root", "zgame");
	guiroot->setelement(new ncgui::split("topsplit", ncgui::VERTICAL, ncgui::partsize(), ncgui::partsize(20)));
	
	guiroot->agetelement<ncgui::split>("topsplit")->setelement(0, new ncgui::textconsole("worldconsole"));
	guiroot->agetelement<ncgui::split>("topsplit")->setelement(1, new ncgui::textconsole("rightshit"));
	
	guiroot->agetelement<ncgui::textconsole>("worldconsole")->showprompt(true);
	
	guiroot->maximize();
	guiroot->redraw();
}

void stop_graphics(){
	endwin();
}


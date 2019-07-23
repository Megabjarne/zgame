
#include <graphics.h>

void build_gui();

ncgui::box *guiroot;

void init_graphics(){
	initscr();
	noecho();
	
	build_gui();
}

void build_gui(){
	// build initial gui stage
	guiroot = new ncgui::box("root", "zgame");
	guiroot->setelement(new ncgui::split("topsplit", ncgui::VERTICAL, ncgui::partsize(), ncgui::partsize(20)));
	
	guiroot->agetelement<ncgui::split>("topsplit")->setelement(0, new ncgui::textconsole("worldconsole"));
	guiroot->agetelement<ncgui::split>("topsplit")->setelement(1, new ncgui::textconsole("rightshit"));
	
	guiroot->maximize();
	guiroot->redraw();
}

void stop_graphics(){
	endwin();
}


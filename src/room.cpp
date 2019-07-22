
#include <room.h>
#include <string>
#include <graphics.h>

using std::list;
using std::string;

room_id nextid = 1;

Room::Room(){
	this->_id = nextid;
	nextid++;
}

room_id Room::id(){
	return this->_id;
}

list<Link*> Room::exits(){
	// get list of links connected to room from map in global game object
	return game.map.exits(this->id());
}

void Room::describe(){
	ncgui::textconsole *console = guiroot->agetelement<ncgui::textconsole>("worldconsole");
	string s = "The room has " + std::to_string(this->exits().size()) + " exits";
	console->addline(s);
	
}


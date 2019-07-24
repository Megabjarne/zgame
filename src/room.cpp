
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

Room::Room(Pos npos) : Room() {
	_pos = npos;
}

room_id Room::id(){
	return this->_id;
}

Pos Room::pos(){
	return _pos;
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

void Room::describe_detailed(){
	ncgui::textconsole *console = guiroot->agetelement<ncgui::textconsole>("worldconsole");
	list<Link*> exitlist = this->exits();
	string s = "The room has " + std::to_string(exitlist.size()) + " exits; ";
	unsigned int n = 0;
	for (auto e = exitlist.begin(); e != exitlist.end(); e++){
		n++;
		if (n == exitlist.size() && exitlist.size() != 1){
			s += " and a ";
		}else{
			if (n != 1)
				s += ", ";
			s += "a ";
		}
		s += string((*e)->stype()) + " leading " + (*e)->direction(this->id());
	}
	console->addline(s);
}


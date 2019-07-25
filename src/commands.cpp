
#include <commands.h>
#include <graphics.h> // DEBUG

using std::string;
using std::list;

bool Command::startswith(string s, string pattern){
	// extract start
	string start = s.substr(0, pattern.size());
	// convert to lowercase
	for (unsigned int i=0; i<start.size(); i++)
		s[i] = std::tolower(s[i]);
	// compare
	return start == pattern;
}

// ############ LOOK ############
list<string> Command_Look::completions(string partialcommand){
	list<string> retlist;
	// base command test
	if (partialcommand.size() <= 5){
		if (startswith("look ", partialcommand)){
			retlist.push_back("look ");
		}
	}
	// base + arg test
	if (startswith(partialcommand, "look")){
		// check exits in the room the player is currently in
		list<Link*> exits = game.player.room()->exits();
		for (auto e = exits.begin(); e != exits.end(); e++){
			string linkstring = "look " + (*e)->direction(game.player.room());
			// if current read string matches with the linkstring
			if (startswith(linkstring, partialcommand))
				retlist.push_back(linkstring);
		}
	}
	return retlist;
}

bool Command_Look::process(std::string command){
	if (startswith(command, "look")){
		// if nothing else is specified, look at the room
		if (command.size() == 4){
			game.player.describe_room_detailed();
		} else
		// look at the specified target
		{
			string target = trim(command.substr(5));
			guiroot->agetelement<ncgui::textconsole>("worldconsole")->addline(string("looking at '") + target + "'");
		}
		return true;
	}else
		return false;
}

// ############ EXIT ############
list<string> Command_Exit::completions(string partialcommand){
	list<string> retlist;
	// base command test
	if (partialcommand.size() <= 4){
		if (startswith("exit", partialcommand)){
			retlist.push_back("exit");
		}
	}
	return retlist;
}

bool Command_Exit::process(std::string command){
	if (startswith(command, "exit")){
		game.stop();
		guiroot->agetelement<ncgui::textconsole>("worldconsole")->addline(string("exiting"));
		return true;
	}
	return false;
}

// ############ MOVE ############
list<string> Command_Move::completions(string partialcommand){
	list<string> retlist;
	// base command test
	if (partialcommand.size() < 4){
		if (startswith("move", partialcommand)){
			retlist.push_back("move ");
		}
	}
	// base + arg test
	if (startswith(partialcommand, "move")){
		// check exits in the room the player is currently in
		list<Link*> exits = game.player.room()->exits();
		for (auto e = exits.begin(); e != exits.end(); e++){
			string linkstring = "move " + (*e)->direction(game.player.room());
			// if current read string matches with the linkstring
			if (startswith(linkstring, partialcommand))
				retlist.push_back(linkstring);
		}
	}
	return retlist;
}

bool Command_Move::process(std::string command){
	if (startswith(command, "move")){
		// check if valid
		if (command.size() == 4){
			guiroot->agetelement<ncgui::textconsole>("worldconsole")->addline("but where should i move?");
		}
		if (!startswith(command, "move ")){
			return false;
		}
		string target = trim(command.substr(5));
		// find the action corresponding to the given target
		// check exits
		list<Link*> exits = game.player.room()->exits();
		for (auto e = exits.begin(); e != exits.end(); e++){
			if (target == (*e)->direction(game.player.room())){
				// this exit is the one specified
				if (game.player.move((*e))){
					guiroot->agetelement<ncgui::textconsole>("worldconsole")->addline(string("you move through the ") + (*e)->stype());
					game.player.describe_room();
				} else {
					guiroot->agetelement<ncgui::textconsole>("worldconsole")->addline("but where should i move?");
				}
			}
		}
		return true;
	}else
		return false;
}


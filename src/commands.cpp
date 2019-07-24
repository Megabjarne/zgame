
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
	if (partialcommand.size() <= 4){
		if (startswith("look", partialcommand)){
			retlist.push_back("look");
		}
	}else
	if (startswith(partialcommand, "look ")){
		retlist.push_back("look [target]");
	}
	return retlist;
}

bool Command_Look::process(std::string command){
	if (startswith(command, "look")){
		// if nothing else is specified, look at the room
		if (command.size() == 4){
			game.player.get_room()->describe_detailed();
		} else
		// look at the specified target
		{
			string target = command.substr(5);
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


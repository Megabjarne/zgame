
#include <game.h>

using std::string;
using std::list;

Game game;

Game::Game(){
	commands.push_back(new Command_Look());
	commands.push_back(new Command_Exit());
}

void Game::run(){
	this->running = true;
	
	while (this->running){
		process_input();
	}
}

void Game::stop(){
	this->running = false;
}

void Game::process_input(){
	ncgui::textconsole *console = guiroot->agetelement<ncgui::textconsole>("worldconsole");
	string read = "";
	
	console->setprompt(string(" > "));
	
	while (1){
		int c = console->igetch();
		// enter
		if (c == '\n'){
			break;
		}else
		// tab
		if (c == '\t'){
			list<string> completions;
			for (auto com = commands.begin(); com != commands.end(); com++){
				completions.merge((*com)->completions(read));
			}
			if (completions.size() == 0){
				console->addline("no completions found");
			}
			if (completions.size() == 1){
				read = completions.front();
				console->setprompt(string(" > ") + read);
			}
			if (completions.size() > 1){
				string s = "completions: ";
				for (auto comp = completions.begin(); comp != completions.end(); comp++){
					s += (*comp) + " | ";
				}
				// remove trailing " | "
				s = s.substr(0, s.size()-3);
				console->addline(s);
			}
		}else
		// backspace
		if (c == '\b' || c == 127 /*DEL key*/){
			if (read.size() != 0)
				read = read.substr(0, read.size()-1);
			console->setprompt(string(" > ") + read);
		}else
		// everything else
		{
			read += c;
			console->setprompt(string(" > ") + read);
		}
	}
	console->setprompt(string(" > "));
	// process the read line
	console->addline(string(" > ") + read);
	// find command that fits
	bool processed = false;
	for (auto com = commands.begin(); com != commands.end(); com++){
		if ((*com)->process(read)){
			processed = true;
			break;
		}
	}
	if (!processed){
		console->addline("sorry, that's not a recognized command");
	}
}


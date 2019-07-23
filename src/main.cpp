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
	ncgui::textconsole *cons = guiroot->agetelement<ncgui::textconsole>("worldconsole");
	cons->showprompt(true);
	string prompt = " > ";
	cons->setprompt(prompt);
	for (int i=0; i<10; i++){
		char c = cons->igetch();
		cons->addline(string("read character '") + c + "'");
		prompt += c;
		cons->setprompt(prompt);
	}
	//usleep(5 * 1000000);
	
	stop_graphics();
	return 0;
}


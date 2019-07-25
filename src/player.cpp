
#include <player.h>
#include <room.h>

using std::string;

Player::Player(){}

void Player::update(){}

void Player::describe_room(){
	ncgui::textconsole *cons = guiroot->agetelement<ncgui::textconsole>("worldconsole");
	cons->addline(
		string("You find yourself in ") + this->room()->describe()
	);
}

void Player::describe_room_detailed(){
	ncgui::textconsole *cons = guiroot->agetelement<ncgui::textconsole>("worldconsole");
	cons->addline(
		string("You find yourself in ") + this->room()->describe_detailed()
	);
}


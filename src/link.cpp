
#include <link.h>

using std::string;

std::string linktype_to_string[] = {"door"};

Link::Link(room_id _room_1, room_id _room_2, linktype ltype){
	room_1 = _room_1;
	room_2 = _room_2;
	_type = ltype;
}

Room* Link::room1(){
	return game.map.get_room(this->room_1);
}

Room* Link::room2(){
	return game.map.get_room(this->room_2);
}

bool Link::connected(room_id roomid){
	return (roomid == this->room_1) || (roomid == this->room_2);
}

void Link::describe(){
	
}

string Link::direction(Room *fromroom){
	return this->direction(fromroom->id());
}
string Link::direction(room_id fromroom){
	Room *from, *to;
	if (fromroom == room_1){
		from = this->room1();
		to = this->room2();
	}else{
		from = this->room2();
		to = this->room1();
	}
	Pos diff = to->pos()-from->pos();
	if (diff == Pos(1,0))
		return "east";
	if (diff == Pos(0,1))
		return "south";
	if (diff == Pos(-1,0))
		return "west";
	if (diff == Pos(0,-1))
		return "north";
	return "";
}

string Link::stype(){
	return linktype_to_string[this->_type];
}


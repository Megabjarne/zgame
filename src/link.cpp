
#include <link.h>

Link::Link(room_id _room_1, room_id _room_2){
	room_1 = _room_1;
	room_2 = _room_2;
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


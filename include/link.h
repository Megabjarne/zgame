#ifndef link_h
#define link_h

class Link;

#include <game.h>
#include <room.h>

class Link {
private:
	room_id room_1, room_2;
public:
	Link(room_id _room_1, room_id _room_2);
	Room* room1();
	Room* room2();
	bool connected(room_id roomid);
};

#endif


#ifndef link_h
#define link_h

class Link;

#include <game.h>
#include <room.h>
#include <pos.h>

#include <string>

enum linktype {
	door = 0
};

class Link {
private:
	room_id room_1, room_2;
	linktype _type;
public:
	Link(room_id _room_1, room_id _room_2, linktype ltype=linktype::door);
	Room* room1();
	Room* room2();
	bool connected(room_id roomid);
	void describe();
	std::string direction(Room *fromroom);
	std::string direction(room_id fromroom);
	std::string stype();
};

#endif


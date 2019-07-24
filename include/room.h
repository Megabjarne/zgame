#ifndef room_h
#define room_h

#include <list>

class Room;
typedef unsigned int room_id;
#include <link.h>
#include <game.h>
#include <pos.h>

class Room {
private:
	room_id _id;
	Pos _pos;
public:
	Room();
	Room(Pos npos);
	room_id id();
	Pos pos();
	std::list<Link*> exits();
	
	void describe();
	void describe_detailed();
};

#endif


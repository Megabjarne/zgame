#ifndef room_h
#define room_h

#include <list>

class Room;
typedef unsigned int room_id;
#include <link.h>
#include <game.h>

class Room {
private:
	room_id _id;
public:
	Room();
	room_id id();
	std::list<Link*> exits();
	
	void describe();
};

#endif


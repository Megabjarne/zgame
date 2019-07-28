#ifndef room_h
#define room_h

#include <list>
#include <string>

class Room;
class Furniture;
typedef unsigned int room_id;
#include <link.h>
#include <game.h>
#include <pos.h>

class Room {
private:
	room_id _id;
	Pos _pos;
public:
	std::list<Furniture*> furniture;
	
	Room();
	Room(Pos npos);
	room_id id();
	Pos pos();
	std::list<Link*> exits();
	
	std::string describe();
	std::string describe_detailed();
};

#endif


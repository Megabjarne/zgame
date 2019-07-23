#ifndef _entity_h
#define _entity_h

#include <string>

typedef unsigned int entity_id;

class Room;

class Entity {
private:
	entity_id _id;
	Room* _room;

public:
	Entity();
	entity_id id();
	Room *get_room();
	void set_room(Room *new_room);
	
	virtual void update() = 0;
};

#endif


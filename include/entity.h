#ifndef _entity_h
#define _entity_h

#include <string>
#include <tagset.h>

typedef unsigned int entity_id;

class Room;
class Link;

class Entity {
private:
	entity_id _id;
	Room* _room;

public:
	Tagset tags = Tagset(tagtype::ENTITY);
	Entity();
	entity_id id();
	Room* room();
	void move(Room *new_room);
	bool move(Link *link);
	
	virtual void update() = 0;
};

#endif


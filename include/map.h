#ifndef map_h
#define map_h

#include <vector>
#include <list>

typedef unsigned int room_id;
class Room;
class Link;

class Map {
private:
	std::vector<Room*> rooms;
	std::vector<Link*> links;
	
public:
	Map();
	std::list<Link*> exits(room_id roomid);
	Room* get_room(room_id roomid);
	
	void generate_map();
};

#endif


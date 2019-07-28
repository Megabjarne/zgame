#include <stdlib.h>

#include <map.h>

#include <link.h>
#include <room.h>


using std::list;

Map::Map(){
	generate_map();
}

std::list<Link*> Map::exits(room_id roomid){
	list<Link*> retlist;
	for (auto linkit = links.begin(); linkit != links.end(); linkit++)
		if ((*linkit)->connected(roomid))
			retlist.push_back(*linkit);
	return retlist;
}

Room* Map::get_room(room_id roomid){
	for (auto roomit = rooms.begin(); roomit != rooms.end(); roomit++)
		if ((*roomit)->id() == roomid)
			return *roomit;
	return nullptr;
}

void Map::generate_map(){
	// add rooms
	rooms.push_back(new Room(Pos(0,0)));
	rooms.push_back(new Room(Pos(1,0)));
	rooms.push_back(new Room(Pos(0,1)));
	// add links
	links.push_back(new Link(rooms[0]->id(), rooms[1]->id()));
	links.push_back(new Link(rooms[1]->id(), rooms[2]->id()));
	links.push_back(new Link(rooms[2]->id(), rooms[0]->id()));
	// add furniture
	rooms[0]->furniture.push_back(new Furniture(furniture_t::CHAIR));
	rooms[1]->furniture.push_back(new Furniture(furniture_t::CHAIR));
	rooms[1]->furniture.push_back(new Furniture(furniture_t::TABLE));
	rooms[2]->furniture.push_back(new Furniture(furniture_t::CHAIR));
	rooms[2]->furniture.push_back(new Furniture(furniture_t::WARDROBE));
}


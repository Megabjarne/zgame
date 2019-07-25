
#include <entity.h>
#include <iostream>
#include <link.h>

entity_id next_id = 1;

Entity::Entity(){
	this->_id = next_id;
	next_id++;
	std::cout<<"entity created\n";
}

entity_id Entity::id(){
	return this->_id;
}

Room* Entity::room(){
	return this->_room;
}

void Entity::move(Room *new_room){
	this->_room = new_room;
}

bool Entity::move(Link *link){
	// given link is not connected to the room the entity is in
	if (!link->connected(this->room()->id())){
		return false;
	}
	// will add stuff here for checking link tags (barricaded, closed, etc)
	// everything passed, we move the entity to the room, that means the room on the opposite side of the link
	this->move( link->opposite(this->room()->id()) );
	return true;
}


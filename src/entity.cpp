
#include <entity.h>
#include <iostream>

entity_id next_id = 1;

Entity::Entity(){
	this->_id = next_id;
	next_id++;
	std::cout<<"entity created\n";
}

entity_id Entity::id(){
	return this->_id;
}

Room* Entity::get_room(){
	return this->_room;
}

void Entity::set_room(Room *new_room){
	this->_room = new_room;
}


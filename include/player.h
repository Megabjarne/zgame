#ifndef _player_h
#define _player_h

#include <entity.h>
#include <graphics.h>
#include <string>

class Player : public Entity {
private:
	

public:
	Player();
	void update();
	void describe_room();
	void describe_room_detailed();
};

#endif


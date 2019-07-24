
#include <pos.h>

Pos::Pos(){
	x=0;
	y=0;
}
Pos::Pos(int _x, int _y){
	x=_x;
	y=_y;
}

Pos operator-(const Pos& p1, const Pos& p2){
	return Pos(p1.x-p2.x, p1.y-p2.y);
}

bool operator==(const Pos& p1, const Pos& p2){
	return (p1.x == p2.x) && (p1.y == p2.y);
}

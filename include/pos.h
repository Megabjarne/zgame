#ifndef _pos_h
#define _pos_h

class Pos {
public:
	int x, y;
	Pos();
	Pos(int _x, int _y);
};

Pos operator-(const Pos& p1, const Pos& p2);

bool operator==(const Pos& p1, const Pos& p2);

#endif


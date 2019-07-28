#ifndef _furniture_h
#define _furniture_h

#include <string>
#include <tagset.h>

enum furniture_t {
	CHAIR,
	TABLE,
	WARDROBE
};

std::string translate(furniture_t type);

class Furniture {
private:
	
public:
	Tagset tags = Tagset(tagtype::FURNITURE);
	furniture_t type;
	
	Furniture(furniture_t t);
	std::string display_name();
};

#endif


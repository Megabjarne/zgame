
#include <furniture.h>
using std::string;

std::string translate(furniture_t type){
	switch (type){
		case CHAIR:
			return "chair";
		case TABLE:
			return "table";
		case WARDROBE:
			return "wardrobe";
	}
	return "unknown furniture type";
}

Furniture::Furniture(furniture_t t){
	type = t;
}

string Furniture::display_name(){
	string s;
	if (this->tags.get(furniture_tag::BROKEN))
		s += "broken ";
	s += translate(this->type);
	return s;
}


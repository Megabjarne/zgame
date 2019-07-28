#ifndef _tagset_h
#define _tagset_h

#include <vector>

enum entity_tag : unsigned int {
	ENTITY_MAX
};

enum furniture_tag : unsigned int {
	BROKEN,
	FURNITURE_MAX
};

enum tagtype : unsigned int {
	ENTITY = ENTITY_MAX,
	FURNITURE = FURNITURE_MAX
};

class Tagset {
private:
	std::vector<bool> _tags;
public:
	Tagset(tagtype type);
	bool get(unsigned int t);
	void set(unsigned int t, bool val);
};

#endif


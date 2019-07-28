
#include <tagset.h>

using std::vector;

Tagset::Tagset(tagtype type){
	_tags = vector<bool>(type, false);
}

bool Tagset::get(unsigned int t){
	return this->_tags[t];
};

void Tagset::set(unsigned int t, bool val){
	this->_tags[t] = val;
};


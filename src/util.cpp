#include <util.h>

using std::string;

string trim(string s){
	while (s.front() == ' '){
		s = s.substr(1);
	}
	while (s.back() == ' '){
		s = s.substr(0, s.size()-1);
	}
	return s;
}


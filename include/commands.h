#ifndef _commands_h
#define _commands_h

#include <list>
#include <string>
#include <cctype>

#include <game.h>
#include <room.h>

class Command {
protected:
	bool startswith(std::string s, std::string pattern);

public:
	// returns a list of completions applying to this command
	virtual std::list<std::string> completions(std::string partialcommand) =0;
	// return true if command-string applies to this command and was executed
	virtual bool process(std::string command) =0;
};

class Command_Look : public Command{
public:
	std::list<std::string> completions(std::string partialcommand);
	bool process(std::string command);
};

class Command_Exit : public Command{
public:
	std::list<std::string> completions(std::string partialcommand);
	bool process(std::string command);
};

#endif


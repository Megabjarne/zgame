
CC = g++
CFLAGS = -Iinclude -Wall -std=c++11
LIBS = -lncurses -lncgui

headerfiles = $(wildcard include/*)
pheaderfiles = $(addprefix include/, $(headerfiles))
objects = $(addsuffix .o, $(basename $(notdir $(wildcard src/*))))
pobjects = $(addprefix obj/, $(objects))

zgame: $(pobjects)
	@printf "compiling program\n"
	@$(CC) $(pobjects) $(CFLAGS) $(LIBS) -o zgame

obj/%.o: src/%.cpp
	@# ensuring existence of obj directory
	@[ ! -e obj/ ] && mkdir obj || true
	@# compiling source files
	@printf "  compiling $(notdir $^)\n"
	@$(CC) -c -o $@ $^ $(LIBS) $(CFLAGS)
	
clean:
	@rm obj/* || true
	@rm zgame || true


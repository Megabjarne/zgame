
CC = g++
CFLAGS = -Iinclude -Wall
LIBS = -lncurses -lncgui

headerfiles = $(wildcard include/*)
pheaderfiles = $(addprefix include/, $(headerfiles))
objects = $(addsuffix .o, $(basename $(notdir $(wildcard src/*))))
pobjects = $(addprefix obj/, $(objects))

all: $(pobjects)
	@printf "compiling program\n"
	@$(CC) $(pobjects) $(CFLAGS) $(LIBS) -o zgame

rebuild: clean all

obj/%.o: src/%.cpp
	@# compiling source files
	@printf "  compiling $(notdir $^)\n"
	@$(CC) -c -o $@ $^ $(LIBS) $(CFLAGS)
	@printf "\n"
	
clean:
	@rm obj/* || true
	@rm zgame || true


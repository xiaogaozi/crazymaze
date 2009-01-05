CC = gcc
CCFLAG = -Wall -g
OBJECT = maze.o create_maze.o load_maze.o dynamic_print.o backtrace.o linklist.o getch.o mazegame.o showmenu.o

maze: $(OBJECT)
	$(CC) $(CCFLAG) -o maze $(OBJECT)

maze.o: maze.c function_prototype.h type_define.h getch.h
	$(CC) $(CCFLAG) -c maze.c

create_maze.o: create_maze.c type_define.h function_prototype.h
	$(CC) $(CCFLAG) -c create_maze.c

load_maze.o: load_maze.c type_define.h
	$(CC) $(CCFLAG) -c load_maze.c

dynamic_print.o: dynamic_print.c type_define.h function_prototype.h
	$(CC) $(CCFLAG) -c dynamic_print.c

backtrace.o: backtrace.c type_define.h function_prototype.h getch.h Makefile
	$(CC) $(CCFLAG) -c backtrace.c

linklist.o: linklist.c type_define.h
	$(CC) $(CCFLAG) -c linklist.c

mazegame.o: mazegame.c type_define.h function_prototype.h getch.h
	$(CC) $(CCFLAG) -c mazegame.c

showmenu.o: showmenu.c getch.h
	$(CC) $(CCFLAG) -c showmenu.c

getch.o: getch.c
	$(CC) $(CCFLAG) -c getch.c

clean:
	rm -f $(OBJECT)

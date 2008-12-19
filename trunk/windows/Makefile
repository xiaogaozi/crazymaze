CC = gcc
CCFLAG = -Wall -g
# LOCFLAG = -I
OBJECT = maze.o

maze.exe: maze.o
	$(CC) $(CCFLAG) -o maze $(OBJECT)

maze.o: maze.c sqstack.h
	$(CC) $(CCFLAG) -c maze.c

clean:
	rm -f $(OBJECT) *~

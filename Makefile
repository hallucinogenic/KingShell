#A Simple Ilustrative Makefile for soshell

#

CC=cc

FLAGS=-c -Wall

LIBS=-lm -lpthread

OBS=main.o execute.o parse.o socp.o calc.o isjpg.o help.o redirects.o aviso.o rocket.o sols.o

all :  kingshell


main.o : shell.h main.c

	$(CC) $(FLAGS) main.c

execute.o : shell.h execute.c

	$(CC) $(FLAGS) execute.c

parse.o : shell.h parse.c

	$(CC) $(FLAGS) parse.c

redirects.o : shell.h redirects.c

	$(CC) $(FLAGS) redirects.c

socp.o: shell.h socp.c

	$(CC) $(FLAGS) socp.c

sols.o : shell.h sols.c

	$(CC) $(FLAGS) sols.c

calc.o: shell.h calc.c

	$(CC) $(FLAGS) calc.c

rocket.o: shell.h rocket.c

	$(CC) $(FLAGS) rocket.c

isjpg.o: shell.h isjpg.c

	$(CC) $(FLAGS) isjpg.c

help.o: shell.h help.c

	$(CC) $(FLAGS) help.c

aviso.o: shell.h aviso.c

		$(CC) $(FLAGS) aviso.c

kingshell : $(OBS)

	$(CC)  -o kingshell  $(OBS) $(LIBS)


clean limpar:

	rm -f kingshell *.o *~

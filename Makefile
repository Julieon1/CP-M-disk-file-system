CC = gcc
CFLAGS = -g -Wall
TARGET = payroll

all: cpmdir

cpmdir: cpmdir.o readFlag.o
	$(CC) $(CFLAGS) -o cpmdir cpmdir.o readFlag.o

cpmdir.o: cpmdir.c readFlag.h
	$(CC) $(CFLAGS) -c cpmdir.c

readFlag.o: readFlag.c
	$(CC) $(CFLAGS) -c readFlag.c

clean:
	$(RM) cpmdir *.o *~

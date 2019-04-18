CC = gcc
CFLAGS = -g -Wall

all: cpmdir

cpmdir: cpmdir.o readFlag.o readDisk.o initializeDisk.o directory.h
	$(CC) $(CFLAGS) -o cpmdir cpmdir.o readFlag.o readDisk.o initializeDisk.o

cpmdir.o: cpmdir.c readFlag.h readDisk.h initializeDisk.h directory.h
	$(CC) $(CFLAGS) -c cpmdir.c

readFlag.o: readFlag.c readFlag.h directory.h
	$(CC) $(CFLAGS) -c readFlag.c

readDisk.o: readDisk.c readDisk.h directory.h
	$(CC) $(CFLAGS) -c readDisk.c

initializeDisk.o: initializeDisk.c initializeDisk.h directory.h
	$(CC) $(CFLAGS) -c initializeDisk.c

clean:
	rm -f *.o cpmdir

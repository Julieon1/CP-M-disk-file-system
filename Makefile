CC = gcc
CFLAGS = -g -Wall

all: cpmdir

cpmdir: cpmdir.o readFlag.o readDisk.o initializeDisk.o Directory.h
	$(CC) $(CFLAGS) -o cpmdir cpmdir.o readFlag.o readDisk.o initializeDisk.o

cpmdir.o: cpmdir.c readFlag.h readDisk.h initializeDisk.h Directory.h
	$(CC) $(CFLAGS) -c cpmdir.c

readFlag.o: readFlag.c readFlag.h Directory.h
	$(CC) $(CFLAGS) -c readFlag.c

readDisk.o: readDisk.c readDisk.h Directory.h
	$(CC) $(CFLAGS) -c readDisk.c

initializeDisk.o: initializeDisk.c initializeDisk.h Directory.h
	$(CC) $(CFLAGS) -c initializeDisk.c

clean:
	$(RM) cpmdir *.o *~

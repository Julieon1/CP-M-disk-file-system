CC = gcc
CFLAGS = -g

all: cpmdir cpmremove

cpmdir: cpmdir.o readFlag.o directoryList.o readDirectory.o
	$(CC) $(CFLAGS) -o cpmdir cpmdir.o readFlag.o directoryList.o readDirectory.o

cpmremove: cpmremove.o readFlag.o readPhysical.o readLogical.o directoryList.o removeDirectory.o readDirectory.o
	$(CC) $(CFLAGS) -o cpmremove cpmremove.o readPhysical.o readLogical.o readFlag.o directoryList.o removeDirectory.o readDirectory.o

cpmremove.o: cpmremove.c readFlag.h directory.h directoryList.h removeDirectory.h 
	$(CC) $(CFLAGS) -c cpmremove.c

cpmdir.o: cpmdir.c readFlag.h directory.h directoryList.h readDirectory.h
	$(CC) $(CFLAGS) -c cpmdir.c

readFlag.o: readFlag.c readFlag.h
	$(CC) $(CFLAGS) -c readFlag.c

readPhysical.o: readPhysical.c readPhysical.h directory.h
	$(CC) $(CFLAGS) -c readPhysical.c

readLogical.o: readLogical.c readLogical.h disk.h directory.h readPhysical.h
	$(CC) $(CFLAGS) -c readLogical.c

directoryList.o: directoryList.c directoryList.h directory.h disk.h readDirectory.h
	$(CC) $(CFLAGS) -c directoryList.c

readDirectory.o: readDirectory.c readDirectory.h directoryList.h
	$(CC) $(CFLAGS) -c readDirectory.c

removeDirectory.o: removeDirectory.c removeDirectory.h directoryList.h disk.h readDirectory.h readLogical.h
	$(CC) $(CFLAGS) -c removeDirectory.c

clean:
	rm -f *.o cpmremove cpmdir

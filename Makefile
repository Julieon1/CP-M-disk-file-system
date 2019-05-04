CC = gcc
CFLAGS = -g

all: cpmdir

cpmdir: cpmdir.o readFlag.o readPhysical.o readLogical.o directoryList.o readDirectory.o
	$(CC) $(CFLAGS) -o cpmdir cpmdir.o readFlag.o readPhysical.o readLogical.o directoryList.o readDirectory.o

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

clean:
	rm -f *.o *.exe

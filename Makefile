CC = gcc
CFLAGS = -g

all: cpmdir cpmremove cpmcreate

cpmdir: cpmdir.o readFlag.o directoryList.o readDirectory.o fileSearch.o fileOutput.o readLogical.o
	$(CC) $(CFLAGS) -o cpmdir cpmdir.o readFlag.o directoryList.o readDirectory.o fileSearch.o fileOutput.o readLogical.o

cpmremove: cpmremove.o readFlag.o directoryList.o removeDirectory.o readDirectory.o
	$(CC) $(CFLAGS) -o cpmremove cpmremove.o readFlag.o directoryList.o removeDirectory.o readDirectory.o

cpmcreate: cpmcreate.o readFlag.o
	$(CC) $(CFLAGS) -o cpmcreate cpmcreate.o readFlag.o

cpmcreate.o: cpmcreate.c readFlag.h directory.h disk.h
	$(CC) $(CFLAGS) -c cpmcreate.c

cpmremove.o: cpmremove.c readFlag.h directory.h directoryList.h removeDirectory.h
	$(CC) $(CFLAGS) -c cpmremove.c

cpmdir.o: cpmdir.c readFlag.h directory.h directoryList.h readDirectory.h fileSearch.h fileOutput.h
	$(CC) $(CFLAGS) -c cpmdir.c

readFlag.o: readFlag.c readFlag.h
	$(CC) $(CFLAGS) -c readFlag.c

readPhysical.o: readPhysical.c readPhysical.h directory.h
	$(CC) $(CFLAGS) -c readPhysical.c

readLogical.o: readLogical.c readLogical.h disk.h directory.h readPhysical.h
	$(CC) $(CFLAGS) -c readLogical.c

directoryList.o: directoryList.c directoryList.h directory.h disk.h readDirectory.h
	$(CC) $(CFLAGS) -c directoryList.c

fileSearch.o: fileSearch.c fileSearch.h directoryList.h readDirectory.h
	$(CC) $(CFLAGS) -c fileSearch.c

fileOutput.o: fileOutput.c fileOutput.h directoryList.h disk.h readLogical.h readDirectory.h
	$(CC) $(CFLAGS) -c fileOutput.c

readDirectory.o: readDirectory.c readDirectory.h directoryList.h
	$(CC) $(CFLAGS) -c readDirectory.c

removeDirectory.o: removeDirectory.c removeDirectory.h directoryList.h disk.h readDirectory.h
	$(CC) $(CFLAGS) -c removeDirectory.c

clean:
	rm -f *.o cpmcreate cpmremove cpmdir


all: cpmdir

cpmdir: cpmdir.o readFlag.o readDisk.o initializeDisk.o
	gcc -o cpmdir cpmdir.o readFlag.o readDisk.o initializeDisk.o

cpmdir.o: cpmdir.c readFlag.h readDisk.h
	gcc -c cpmdir.c

readFlag.o: readFlag.c readFlag.h directory.h
	gcc -c readFlag.c

readDisk.o: readDisk.c readDisk.h initializeDisk.h directory.h
	gcc -c readDisk.c

initializeDisk.o: initializeDisk.c initializeDisk.h directory.h
	gcc -c initializeDisk.c

clean:
	rm -f *.o cpmdir

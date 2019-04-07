# Terrence, Kei, Julieon

# Final Requirements

* Be able to open up and read the disk
* Build a Structure that can read and contain the data from the disks
* Identify the flags that determine the type of disk (floppy (-f), hard (-h))
* Identify the boot tracks and file directories of the disks
* Be able to read the file directories and use them to locate the data on the disks
* Adjust for a skew in floppy disk
* Be able to locate the specified directories, file, or files within the disk image

### cpmdir

 * print out and display contents of the disk image (Including the empty spaces)
 * print out just the directories that contain data (find directories function)




### cpmcreate

 * Create an empty disk containing no file entries



### cpmcopy

 * Determine if there is enough space left in the file we are copying data to
 * Determine where the data is to be copied
 * Add the data to the specified file and mark it in the file directory


### cpmremove

 * Mark the files in the specified file directory to be empty

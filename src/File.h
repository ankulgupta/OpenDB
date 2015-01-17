#ifndef FILE_H
#define FILE_H
#include <sys/types.h> // off_t is used to define the file offsets
#include "page.h"
/**
* File representation of the underlying memory.
* Provides read/write API for the underlying storage memory.
* Used by the Disk Manager.
**/

/**
-> descriptor of the file is stored in the myfileDes.
-> FileName is sufficient to open the file.
-> The disk manager will maintain a table of file_name v/s fd and it will get the File Descriptor
   by opening the file by using openDb method of the File Class.
-> The first sizeof(off_t) bytes of the header page tells the current length of the file, i.e the number
   of pages in the file.
-> One instance of the Class File for a single database file.
-> length = 1 means that only the header page conataining the meta information exists.
-> length = 0 means that no page exists in the file.
**/

class File
{
 private:
	int myfileDes; // Descriptor of the file
	off_t currLength; // number of pages in the file

	// Constructor
	File();

	// get the current length of the file in pages  
	static off_t getLength();

	// Opens the database file with the given fname and point the file descriptor to 
	// the page pointed out by the length
	// length can't be zero, if it zero then the dbfile does not exist
	static void openDb(int length,char* fname);

	// create the database file
	// add the file descriptor information to the meta file or catalog
	static void createDb(char* fname);

	// Adds the page to the db file with a given offset
	// Storage Manager or someone else will check for the free page availability by reading
	// the meta information on the pages
	// deleting a page is simply replacing a page
	static int addPage(Page* addMe,off_t page_off);

	// Allows someone to get a page by using the page_off information
	static int getPage(Page* getMe,off_t page_off);

	// Closes the file and return current length
	static off_t close();

};

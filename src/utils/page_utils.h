#ifndef PAGE_UTILS_H
#define PAGE_UTILS_H

/**
* Utilities for reading and writing to the underlying storage array of Page object 
* and not to the disk i.e in memory.
**/
friend class page;
friend class record;

short readShort(char* block,short offset);

void writeShort(char* block,short offset,short value);

int readInt(char* block,short offset);

void writeInt(char* block,short offset,int value);

char* readBytes(char* block,short offset,int length);

void writeBytes(char* block,short offset,int length,const char* data_block);

void moveBytes(char* block,short src_off,short dest_off,short chunk_length);

int readDouble(char* block,short offset);

void writeDouble(char* block,short offset,double value);

#endif


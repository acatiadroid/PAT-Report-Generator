#ifndef XMLFILEINDEXPARSER_H
#define XMLFILEINDEXPARSER_H

#include <tinyxml2.h>
#include <string>

int generateIndexID();

void createNewFileIndexEntry();

bool CheckFileIndexExists();

void addNewFileIndexEntry(const char* location);




#endif
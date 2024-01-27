#ifndef XMLFILEINDEXPARSER_H
#define XMLFILEINDEXPARSER_H
#define GLOG_NO_ABBREVIATED_SEVERITIES

#include <tinyxml2.h>
#include <string>

int generateIndexID();

bool checkFileIndexExists();

int addNewFileIndexEntry();


#endif
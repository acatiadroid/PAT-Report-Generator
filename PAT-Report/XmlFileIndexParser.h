#ifndef XMLFILEINDEXPARSER_H
#define XMLFILEINDEXPARSER_H
#define GLOG_NO_ABBREVIATED_SEVERITIES

#include <tinyxml2.h>
#include <string>

std::string generateIndexID();

bool checkFileIndexExists();

std::string addNewFileIndexEntry();


#endif
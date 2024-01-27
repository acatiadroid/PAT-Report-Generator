#ifndef XMLPARSERUTILS_H
#define XMLPARSERUTILS_H
#define GLOG_NO_ABBREVIATED_SEVERITIES

#include <tinyxml2.h>

const char* getFilePath(const char* which);

const char* getReportFilePath(int reportNumber);

bool saveXMLfile(tinyxml2::XMLDocument, const char* fp);

#endif
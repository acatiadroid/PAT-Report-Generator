#ifndef XMLPARSERUTILS_H
#define XMLPARSERUTILS_H
#define GLOG_NO_ABBREVIATED_SEVERITIES

#include <tinyxml2.h>
#include <string>

std::string getFilePath(const char* which);

std::string getReportFilePath(std::string reportNumber);

bool saveXMLfile(tinyxml2::XMLDocument&, const char* fp);

#endif
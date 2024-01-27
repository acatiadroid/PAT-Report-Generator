#ifndef XMLREPORTPARSER_H
#define XMLREPORTPARSER_H
#define GLOG_NO_ABBREVIATED_SEVERITIES

#include <tinyxml2.h>

void createNewReport(
	const char* name,
	const char* company,
	const char* address,
	const char* postcode,
	const char* phone,
	const char* email,
	const char* date
);

#endif
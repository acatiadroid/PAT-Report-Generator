#ifndef XMLREPORTPARSER_H
#define XMLREPORTPARSER_H
#define GLOG_NO_ABBREVIATED_SEVERITIES

#include <tinyxml2.h>
#include <string>

void createReportFile(std::string path);

void createNewReport(
	std::string name,
	std::string company,
	std::string address,
	std::string postcode,
	std::string phone,
	std::string email,
	std::string date
);

#endif
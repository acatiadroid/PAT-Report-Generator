#ifndef XMLPROJECTSETTINGSPARSER_H
#define XMLPROJECTSETTINGSPARSER_H
#define GLOG_NO_ABBREVIATED_SEVERITIES

#include <tinyxml2.h>
#include <filesystem>

bool checkProjectSettingsExists();

void createProjectSettingsFile();

#endif
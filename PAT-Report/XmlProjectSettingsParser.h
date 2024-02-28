#ifndef XMLPROJECTSETTINGSPARSER_H
#define XMLPROJECTSETTINGSPARSER_H
#define GLOG_NO_ABBREVIATED_SEVERITIES

#include <tinyxml2.h>
#include <filesystem>
#include <string>

std::filesystem::path getLoggingDirPath();
/*
const char* getFileIndexPath();

const char* getProjectSettingsPath();
*/
bool checkProjectSettingsExists(std::filesystem::path fp);

bool createProjectSettingsFile();

#endif
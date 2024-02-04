#include "XmlParserUtils.h"

#include <tinyxml2.h>
#include <glog/logging.h>
#include <filesystem>
#include <string>

std::string getFilePath(const char* which) {
    std::filesystem::path workingDir = std::filesystem::current_path();
    std::filesystem::path filePath;

    if (which == "ProjectSettings") {
        std::filesystem::path fileName = "..\\Data\\ProjectSettings.xml";
        filePath = workingDir / fileName;
    }
    else if (which == "FileIndex") {
        std::filesystem::path fileName = "..\\Data\\FileIndex.xml";
        filePath = workingDir / fileName;
    }
    else {
        filePath = workingDir;
    }

    std::string strPath = filePath.string();

    return strPath;
}

std::string getReportFilePath(std::string reportNumber) {
    std::filesystem::path workingDir = std::filesystem::current_path();
    std::filesystem::path filePath;
    std::filesystem::path fileName = std::string("..\\Data\\Reports\\") + reportNumber + std::string(".xml");

    LOG(INFO) << fileName;
    LOG(INFO) << reportNumber;

    filePath = workingDir / fileName;

    std::string strPath = filePath.string();

    return strPath;
}

bool saveXMLfile(tinyxml2::XMLDocument& doc, const char* fp) {
    if (doc.SaveFile(fp) == tinyxml2::XML_SUCCESS) {
        LOG(INFO) << "Successfully saved XML document";
        return true;
    }
    else {
        LOG(ERROR) << "Failed to save XML document - check project settings file";
        LOG(ERROR) << doc.ErrorStr();
        return false;
    }
}
#include "XmlParserUtils.h"

#include <tinyxml2.h>
#include <glog/logging.h>
#include <filesystem>

const char* getFilePath(const char* which) {
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
    const char* charPath = strPath.c_str();

    return charPath;
}

const char* getReportFilePath(int reportNumber) {
    std::filesystem::path workingDir = std::filesystem::current_path();
    std::filesystem::path filePath;
    std::filesystem::path fileName = std::string("..\\Data\\Reports\\") + std::to_string(reportNumber) + std::string(".xml");
    filePath = workingDir / fileName;

    std::string strPath = filePath.string();
    const char* charPath = strPath.c_str();

    return charPath;
}

bool saveXMLfile(tinyxml2::XMLDocument doc, const char* fp) {
    if (doc.SaveFile(fp) == tinyxml2::XML_SUCCESS) {
        LOG(INFO) << "Successfully saved XML document";
        return true;
    }
    else {
        LOG(ERROR) << "Failed to save XML document - check project settings file";
        return false;
    }
}
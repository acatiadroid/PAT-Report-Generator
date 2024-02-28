#include "XmlProjectSettingsParser.h"
#include "XmlParserUtils.h"

#include <tinyxml2.h>
#include <glog/logging.h>
#include <filesystem>
#include <string>



std::filesystem::path getLoggingDirPath() {
    tinyxml2::XMLDocument document;
    document.LoadFile(getFilePath("ProjectSettings").c_str());

    tinyxml2::XMLElement* root = document.FirstChildElement("ProjectSettings");
    const char* element = root->FirstChildElement("LoggingDir")->GetText();

    LOG(INFO) << root->FirstChildElement("LoggingDir")->GetText();

    std::filesystem::path path = root->FirstChildElement("LoggingDir")->GetText();

    return path;
}
/*
const char* getFileIndexPath() {

}

const char* getProjectSettingsPath() {

}*/


bool createProjectSettingsFile() {

    tinyxml2::XMLDocument doc;

    const char* fp = getFilePath("ProjectSettings").c_str();

    tinyxml2::XMLElement* root = doc.NewElement("ProjectSettings");

    tinyxml2::XMLElement* fileIndex = doc.NewElement("FileIndexFile");
    tinyxml2::XMLElement* projectSettings = doc.NewElement("ProjectSettingsFile");

    fileIndex->SetText(getFilePath("FileIndex").c_str());
    projectSettings->SetText(getFilePath("ProjectSettings").c_str());

    root->InsertEndChild(fileIndex);
    root->InsertEndChild(projectSettings);

    if (saveXMLfile(doc, getFilePath("ProjectSettings").c_str())) {
        return true;
    }
    else {
        return false;
    }
}

bool checkProjectSettingsExists(std::filesystem::path fp) {
    std::filesystem::path filePath;
    std::filesystem::path fileName = std::string("..\\Data\\ProjectSettings.xml");

    filePath = fp / fileName;
    
    if (std::filesystem::exists(filePath)) {
        return true;
    }
    
    return false;
}
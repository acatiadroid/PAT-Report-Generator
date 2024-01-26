#include "XmlProjectSettingsParser.h"

#include <tinyxml2.h>
#include <glog/logging.h>
#include <filesystem>
#include <string>

const char* getFilePath(bool workingDirectory) {
    std::filesystem::path workingDir = std::filesystem::current_path();
    std::filesystem::path filePath;

    if (!workingDirectory) {
        std::filesystem::path fileName = "..\\Data\\example.txt";
        filePath = workingDir / fileName;
    }
    else {
        filePath = workingDir;
    }

    std::string strPath = filePath.string();
    const char* charPath = strPath.c_str();
    
    return charPath;    
}

bool checkProjectSettingsExists() {
    tinyxml2::XMLDocument doc;

    if (doc.LoadFile(getFilePath(false)) == tinyxml2::XML_SUCCESS) {
        return true;
    }
    else {
        return false;
    }
}

void createProjectSettingsFile() {

    tinyxml2::XMLDocument doc;

    const char* fp = getFilePath(false);

    if (doc.LoadFile(fp) != tinyxml2::XML_SUCCESS) {
        LOG(ERROR) << "Error loading Project settings file: not XML_SUCCESS";
        return;
    }


    tinyxml2::XMLElement* windowName = doc.NewElement("WindowName");
    tinyxml2::XMLElement* rootDirectory = doc.NewElement("RootDirectory");

    windowName->SetText("Pat Report Generator");
    rootDirectory->SetText(getFilePath(true));

    root->InsertEndChild(windowName);
    root->InsertEndChild(rootDirectory);

    if (doc.SaveFile(fp) == tinyxml2::XML_SUCCESS) {
        LOG(INFO) << "Successfully created Project Settings";
    }
    else {
        LOG(ERROR) << "Failed to create Project Settings";
    }
}
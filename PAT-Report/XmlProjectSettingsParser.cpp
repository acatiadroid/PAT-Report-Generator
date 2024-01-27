#include "XmlProjectSettingsParser.h"
#include "XmlParserUtils.h"

#include <tinyxml2.h>
#include <glog/logging.h>
#include <filesystem>
#include <string>



//const char* getProjectSettings() {

//}

void createProjectSettingsFile() {

    tinyxml2::XMLDocument doc;

    const char* fp = getFilePath("ProjectSettings");

    tinyxml2::XMLElement* root = doc.NewElement("ProjectSettings");

    tinyxml2::XMLElement* fileIndex = doc.NewElement("FileIndexFile");
    tinyxml2::XMLElement* projectSettings = doc.NewElement("ProjectSettingsFile");

    fileIndex->SetText(getFilePath("FileIndex"));
    projectSettings->SetText(getFilePath("ProjectSettings"));

    root->InsertEndChild(fileIndex);
    root->InsertEndChild(projectSettings);

    saveXMLfile(&doc, getFilePath("ProjectSettings"));
}

void checkProjectSettingsExists() {
    tinyxml2::XMLDocument doc;

    if (doc.LoadFile(getFilePath("ProjectSettings")) != tinyxml2::XML_SUCCESS) {
        createProjectSettingsFile();
    }
}
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

    const char* fp = getFilePath("ProjectSettings").c_str();

    tinyxml2::XMLElement* root = doc.NewElement("ProjectSettings");

    tinyxml2::XMLElement* fileIndex = doc.NewElement("FileIndexFile");
    tinyxml2::XMLElement* projectSettings = doc.NewElement("ProjectSettingsFile");

    fileIndex->SetText(getFilePath("FileIndex").c_str());
    projectSettings->SetText(getFilePath("ProjectSettings").c_str());

    root->InsertEndChild(fileIndex);
    root->InsertEndChild(projectSettings);

    saveXMLfile(doc, getFilePath("ProjectSettings").c_str());
}

void checkProjectSettingsExists() {
    tinyxml2::XMLDocument doc;

    if (doc.LoadFile(getFilePath("ProjectSettings").c_str()) != tinyxml2::XML_SUCCESS) {
        createProjectSettingsFile();
    }
}
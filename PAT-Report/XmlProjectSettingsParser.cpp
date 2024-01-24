#include "XmlProjectSettingsParser.h"

#include <tinyxml2.h>
#include <glog/logging.h>
#include <filesystem>


bool checkProjectSettingsExists() {
	std::filesystem::path currentPath = std::filesystem::current_path();
	
	tinyxml2::XMLDocument doc;

	if (doc.LoadFile("") == tinyxml2::XML_SUCCESS) {
		return true;
	}
	else {
		tinyxml2::XMLDocument doc;
		tinyxml2::XMLElement* root = doc.NewElement("FileIndex");
		doc.InsertFirstChild(root);

		if (doc.LoadFile(FILE_PATH) != tinyxml2::XML_SUCCESS) {
			return false;
		}
	}
}

void createProjectSettingsFile() {

}
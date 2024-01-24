#include "XmlFileIndexParser.h"

#include <tinyxml2.h>
#include <glog/logging.h>
#include <string>
#include <random>
#include <iostream>

const char* FILE_PATH = "C:/Users/lukeh/Documents/c++/PAT-Report/Data/FileIndex.xml";

int generateIndexID() {
	LOG(INFO) << "Generating new index id";

	std::random_device device;
	std::mt19937 rng(device());
	std::uniform_int_distribution < std::mt19937::result_type> dist6(1000, 9999);

	return dist6(rng);
};

void addNewFileIndexEntry(const char* location) {
	LOG(INFO) << "Adding new file index entry";
	tinyxml2::XMLDocument doc;
	if (doc.LoadFile(FILE_PATH) != tinyxml2::XML_SUCCESS) {
		LOG(ERROR) << "tinyxml couldnt load FileIndex.xml";
		return;
	}

	tinyxml2::XMLElement* root = doc.RootElement();
	if (!root) {
		LOG(ERROR) << "tinyxml couldnt get root XML element";
		return;
	}

	int id = generateIndexID();

	tinyxml2::XMLElement* outerElement = doc.NewElement("ReportInfo");
	tinyxml2::XMLElement* idElement = doc.NewElement("ReportID");
	tinyxml2::XMLElement* nameElement = doc.NewElement("ReportLocation");

	idElement->SetText(id);
	nameElement->SetText(location);

	outerElement->InsertEndChild(idElement);
	outerElement->InsertEndChild(nameElement);

	root->InsertEndChild(outerElement);

	if (doc.SaveFile(FILE_PATH) == tinyxml2::XML_SUCCESS) {
		LOG(INFO) << "New file index entry saved successfully.";
	}
	else {
		LOG(ERROR) << "failed to save file index entry";
	}

};
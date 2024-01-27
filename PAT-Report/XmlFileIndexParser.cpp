#include "XmlFileIndexParser.h"
#include "XmlParserUtils.h"

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

bool checkFileIndexExists() {
	tinyxml2::XMLDocument doc;

	if (doc.LoadFile(getFilePath("FileIndex")) == tinyxml2::XML_SUCCESS) {
		return true;
	}
	else {
		tinyxml2::XMLDocument doc;
		tinyxml2::XMLElement* root = doc.NewElement("FileIndex");
		doc.InsertFirstChild(root);

		if (doc.LoadFile(FILE_PATH) != tinyxml2::XML_SUCCESS) {
			return false;
		}
		
		return true;
	}
};

int addNewFileIndexEntry() {
	LOG(INFO) << "Adding new file index entry";
	tinyxml2::XMLDocument doc;

	LOG(ERROR) << getFilePath("FileIndex");

	if (doc.LoadFile(getFilePath("FileIndex")) != tinyxml2::XML_SUCCESS) {
		LOG(ERROR) << "tinyxml couldnt load FileIndex.xml";
		return 0;
	}

	tinyxml2::XMLElement* root = doc.RootElement();
	if (!root) {
		LOG(ERROR) << "tinyxml couldnt get root XML element";
		return 0;
	}

	int id = generateIndexID();

	tinyxml2::XMLElement* outerElement = doc.NewElement("ReportInfo");
	tinyxml2::XMLElement* idElement = doc.NewElement("ReportID");

	idElement->SetText(id);

	outerElement->InsertEndChild(idElement);

	root->InsertEndChild(outerElement);

	saveXMLfile(&doc, getFilePath("FileIndex"));

	return id;

};
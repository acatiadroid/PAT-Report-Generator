#include "XmlFileIndexParser.h"
#include "XmlParserUtils.h"

#include <tinyxml2.h>
#include <glog/logging.h>
#include <string>
#include <random>
#include <iostream>

const char* FILE_PATH = "C:/Users/lukeh/Documents/c++/PAT-Report/Data/FileIndex.xml";

std::string generateIndexID() {
	LOG(INFO) << "Generating new index id";

	std::random_device device;
	std::mt19937 rng(device());
	std::uniform_int_distribution < std::mt19937::result_type> dist6(1000, 9999);

	return std::to_string(dist6(rng));
};

bool checkFileIndexExists() {
	tinyxml2::XMLDocument doc;

	if (doc.LoadFile(getFilePath("FileIndex").c_str()) == tinyxml2::XML_SUCCESS) {
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

std::string addNewFileIndexEntry() {
	LOG(INFO) << "Adding new file index entry";
	tinyxml2::XMLDocument doc;

	if (doc.LoadFile(getFilePath("FileIndex").c_str()) != tinyxml2::XML_SUCCESS) {
		LOG(ERROR) << "tinyxml couldnt load FileIndex.xml";
		return "";
	}

	tinyxml2::XMLElement* root = doc.RootElement();
	if (!root) {
		LOG(ERROR) << "tinyxml couldnt get root XML element";
		return "";
	}

	std::string id = generateIndexID();

	tinyxml2::XMLElement* outerElement = doc.NewElement("ReportInfo");
	tinyxml2::XMLElement* idElement = doc.NewElement("ReportID");

	idElement->SetText(id.c_str());

	outerElement->InsertEndChild(idElement);

	root->InsertEndChild(outerElement);

	saveXMLfile(doc, getFilePath("FileIndex").c_str());

	return id;

};
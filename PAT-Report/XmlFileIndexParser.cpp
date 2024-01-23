#include "XmlFileIndexParser.h"

#include <tinyxml2.h>
#include <string>
#include <random>
#include <iostream>

const char* FILE_PATH = "C:/Users/quzon/Documents/C++/PAT Report Generator/Data/FileIndex.xml";

void createNewFileIndex() {
	tinyxml2::XMLDocument doc;

	tinyxml2::XMLElement* root = doc.NewElement("FileIndex");
	doc.InsertFirstChild(root);

	tinyxml2::XMLElement* element = doc.NewElement("Test");
	element->SetText("etst");

	root->InsertEndChild(element);

	if (doc.SaveFile(FILE_PATH) == tinyxml2::XML_SUCCESS) {
		// don't need to do anything
	}
};

int generateIndexID() {
	std::random_device device;
	std::mt19937 rng(device());
	std::uniform_int_distribution < std::mt19937::result_type> dist6(1000, 9999);

	return dist6(rng);
};

bool checkFileIndexExists() {
	tinyxml2::XMLDocument doc;

	if (doc.LoadFile(FILE_PATH) == tinyxml2::XML_SUCCESS) {
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
};

void addNewFileIndexEntry(const char* location) {
	tinyxml2::XMLDocument doc;
	if (doc.LoadFile(FILE_PATH) != tinyxml2::XML_SUCCESS) {
		createNewFileIndex();
		return;
	}

	tinyxml2::XMLElement* root = doc.RootElement();
	if (!root) {
		std::cout << "No root element";
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

	if (doc.SaveFile(FILE_PATH) == tinyxml2::XML_SUCCESS) {
	}
	else {
	}
};
#include "XmlFileIndexParser.h"

#include <tinyxml2.h>
#include <string>
#include <random>
#include <iostream>
using namespace tinyxml2;

int generateIndexID() {
	std::random_device device;
	std::mt19937 rng(device());
	std::uniform_int_distribution < std::mt19937::result_type> dist6(1000, 9999);

	return dist6(rng);
};
// int indexID, std::string fileName
void createNewFileIndexEntry() {
	XMLDocument doc;

	XMLElement* root = doc.NewElement("RootElement");
	doc.InsertFirstChild(root);

	XMLElement* element = doc.NewElement("TestElement");
	element->SetAttribute("TestAttr", 1.0);
	element->SetText("Something random");

	root->InsertEndChild(element);

	if (doc.SaveFile("C:\\Users\\lukeh\\Documents\\c++\\PAT-Report") == XML_SUCCESS) {
		std::cout << "Saved file";
	}
	else {
		std::cout << "File not saved.";
	}
};
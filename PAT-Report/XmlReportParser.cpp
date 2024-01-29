#include "XmlReportParser.h"
#include "XmlParserUtils.h"
#include "XmlFileIndexParser.h"

#include <tinyxml2.h>
#include <glog/logging.h>
#include <string>

void createNewReport(
	const char* name,
	const char* company,
	const char* address,
	const char* postcode,
	const char* phone,
	const char* email,
	const char* date
) {
	std::string reportID = addNewFileIndexEntry();

	std::string fp = getReportFilePath(reportID);
	
	tinyxml2::XMLDocument doc;

	tinyxml2::XMLElement* rootElement = doc.NewElement("Report");

	tinyxml2::XMLElement* nameElement = doc.NewElement("Name");
	nameElement->SetText(name);

	tinyxml2::XMLElement* companyElement = doc.NewElement("Company");
	companyElement->SetText(company);
	
	tinyxml2::XMLElement* addressElement = doc.NewElement("Address");
	addressElement->SetText(address);
	
	tinyxml2::XMLElement* postcodeElement = doc.NewElement("Postcode");
	postcodeElement->SetText(postcode);
	
	tinyxml2::XMLElement* phoneElement = doc.NewElement("Phone");
	phoneElement->SetText(phone);
	
	tinyxml2::XMLElement* emailElement = doc.NewElement("Email");
	emailElement->SetText(email);

	tinyxml2::XMLElement* dateElement = doc.NewElement("Date");
	dateElement->SetText(date);

	tinyxml2::XMLElement* entries = doc.NewElement("Entries");

	rootElement->InsertEndChild(nameElement);
	rootElement->InsertEndChild(companyElement);
	rootElement->InsertEndChild(addressElement);
	rootElement->InsertEndChild(postcodeElement);
	rootElement->InsertEndChild(phoneElement);
	rootElement->InsertEndChild(emailElement);
	rootElement->InsertEndChild(dateElement);
	rootElement->InsertEndChild(entries);

	LOG(INFO) << fp;

	if (doc.SaveFile(fp.c_str()) == tinyxml2::XML_SUCCESS) {
		LOG(INFO) << "Created new XML report file.";
	}
	else {
		LOG(ERROR) << "Failed to create new XML report file.";
	}
}
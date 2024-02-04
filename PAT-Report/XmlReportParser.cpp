#include "XmlReportParser.h"

#include "XmlParserUtils.h"
#include "XmlFileIndexParser.h"

#include <tinyxml2.h>
#include <glog/logging.h>
#include <stdio.h>
#include <string>

void createReportFile(std::string path) {
	tinyxml2::XMLDocument doc;
	tinyxml2::XMLElement* root = doc.NewElement("Report");
	doc.InsertFirstChild(root);

	doc.SaveFile(path.c_str());
}

void createNewReport(
	std::string name,
	std::string company,
	std::string address,
	std::string postcode,
	std::string phone,
	std::string email,
	std::string date
) {
	std::string reportID = addNewFileIndexEntry();

	std::string fp = getReportFilePath(reportID);
	
	createReportFile(fp);

	tinyxml2::XMLDocument doc;

	if (doc.LoadFile(fp.c_str()) != tinyxml2::XML_SUCCESS) {
		LOG(ERROR) << "tinyxml couldnt load report file";
		return;
	}

	tinyxml2::XMLElement* rootElement = doc.RootElement();
	if (!rootElement) {
		LOG(ERROR) << "tinyxml couldnt get root XML element";
		return;
	}

	tinyxml2::XMLElement* reportNumberElement = doc.NewElement("ReportNumber");
	reportNumberElement->SetText(reportID.c_str());

	tinyxml2::XMLElement* nameElement = doc.NewElement("Name");
	nameElement->SetText(name.c_str());

	tinyxml2::XMLElement* companyElement = doc.NewElement("Company");
	companyElement->SetText(company.c_str());

	tinyxml2::XMLElement* addressElement = doc.NewElement("Address");
	addressElement->SetText(address.c_str());

	tinyxml2::XMLElement* postcodeElement = doc.NewElement("Postcode");
	postcodeElement->SetText(postcode.c_str());

	tinyxml2::XMLElement* phoneElement = doc.NewElement("Phone");
	phoneElement->SetText(phone.c_str());

	tinyxml2::XMLElement* emailElement = doc.NewElement("Email");
	emailElement->SetText(email.c_str());

	tinyxml2::XMLElement* dateElement = doc.NewElement("Date");
	dateElement->SetText(date.c_str());

	tinyxml2::XMLElement* entries = doc.NewElement("Entries");

	rootElement->InsertEndChild(reportNumberElement);
	rootElement->InsertEndChild(nameElement);
	rootElement->InsertEndChild(companyElement);
	rootElement->InsertEndChild(addressElement);
	rootElement->InsertEndChild(postcodeElement);
	rootElement->InsertEndChild(phoneElement);
	rootElement->InsertEndChild(emailElement);
	rootElement->InsertEndChild(dateElement);
	rootElement->InsertEndChild(entries);

	saveXMLfile(doc, fp.c_str());
}
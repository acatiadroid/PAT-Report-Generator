#include "CreateReportFrame.h"
#include "XmlFileIndexParser.h"

#include <wx/msgdlg.h>

wxBEGIN_EVENT_TABLE(CreateReportFrame, wxFrame)
EVT_BUTTON(wxID_ANY, CreateReportFrame::OnSubmitButtonClick)
wxEND_EVENT_TABLE()

CreateReportFrame::CreateReportFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
	: wxFrame(nullptr, wxID_ANY, title, pos, size) {

	lblName = new wxStaticText(this, wxID_ANY, "Name(s):");
	txtName = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);

	lblCompany = new wxStaticText(this, wxID_ANY, "Company:");
	txtCompany = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);

	lblAddress = new wxStaticText(this, wxID_ANY, "Address:");
	txtAddress = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);

	lblPostcode = new wxStaticText(this, wxID_ANY, "Postcode:");
	txtPostcode = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);

	lblPhone = new wxStaticText(this, wxID_ANY, "Phone No.:");
	txtPhone = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);

	lblEmail = new wxStaticText(this, wxID_ANY, "Email:");
	txtEmail = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);

	lblDate = new wxStaticText(this, wxID_ANY, "Date:");
	txtDate = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);

	btnSubmit = new wxButton(this, wxID_ANY, "Submit");
	btnSubmit->Bind(wxEVT_BUTTON, &CreateReportFrame::OnSubmitButtonClick, this);

	// Setup layouts for adding widgets to.
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* rowSizer1 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* rowSizer2 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* rowSizer3 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* rowSizer4 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* rowSizer5 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* rowSizer6 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* rowSizer7 = new wxBoxSizer(wxHORIZONTAL);

	rowSizer1->Add(lblName, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);
	rowSizer1->Add(txtName, 1, wxEXPAND | wxALL, 5);

	rowSizer2->Add(lblCompany, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);
	rowSizer2->Add(txtCompany, 1, wxEXPAND | wxALL, 5);

	rowSizer3->Add(lblAddress, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);
	rowSizer3->Add(txtAddress, 1, wxEXPAND | wxALL, 5);

	rowSizer4->Add(lblPostcode, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);
	rowSizer4->Add(txtPostcode, 1, wxEXPAND | wxALL, 5);

	rowSizer5->Add(lblPhone, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);
	rowSizer5->Add(txtPhone, 1, wxEXPAND | wxALL, 5);

	rowSizer6->Add(lblEmail, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);
	rowSizer6->Add(txtEmail, 1, wxEXPAND | wxALL, 5);

	rowSizer7->Add(lblDate, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);
	rowSizer7->Add(txtDate, 1, wxEXPAND | wxALL, 5);

	mainSizer->Add(rowSizer1, 0, wxEXPAND | wxALL, 5);
	mainSizer->Add(rowSizer2, 0, wxEXPAND | wxALL, 5);
	mainSizer->Add(rowSizer3, 0, wxEXPAND | wxALL, 5);
	mainSizer->Add(rowSizer4, 0, wxEXPAND | wxALL, 5);
	mainSizer->Add(rowSizer5, 0, wxEXPAND | wxALL, 5);
	mainSizer->Add(rowSizer6, 0, wxEXPAND | wxALL, 5);
	mainSizer->Add(rowSizer7, 0, wxEXPAND | wxALL, 5);
	mainSizer->Add(btnSubmit, 0, wxALIGN_CENTER | wxALL, 10);

	SetSizer(mainSizer);
	Bind(wxEVT_CLOSE_WINDOW, &CreateReportFrame::OnClose, this);
}

void CreateReportFrame::OnClose(wxCloseEvent& event) {
	Destroy();
}

void CreateReportFrame::OnSubmitButtonClick(wxCommandEvent& event) {
	createNewFileIndexEntry();
}


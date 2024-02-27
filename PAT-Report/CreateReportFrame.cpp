#include "CreateReportFrame.h"
#include "ReportEditorFrame.h"
#include "XmlFileIndexParser.h"
#include "XmlReportParser.h"
#include "ReportItemTableFrame.h"

#include <wx/msgdlg.h>
#include <glog/logging.h>

wxBEGIN_EVENT_TABLE(CreateReportFrame, wxFrame)
EVT_BUTTON(wxID_ANY, CreateReportFrame::OnSubmitButtonClick)
wxEND_EVENT_TABLE()

CreateReportFrame::CreateReportFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
	: wxFrame(nullptr, wxID_ANY, title, pos, size) {

	LOG(INFO) << "Opened CreateReportFrame Window. Constructing widgets...";

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

	txtName->Bind(wxEVT_CHAR, &CreateReportFrame::OnChar, this);
	txtCompany->Bind(wxEVT_CHAR, &CreateReportFrame::OnChar, this);
	txtAddress->Bind(wxEVT_CHAR, &CreateReportFrame::OnChar, this);
	txtPostcode->Bind(wxEVT_CHAR, &CreateReportFrame::OnChar, this);
	txtPhone->Bind(wxEVT_CHAR, &CreateReportFrame::OnChar, this);
	txtEmail->Bind(wxEVT_CHAR, &CreateReportFrame::OnChar, this);
	txtDate->Bind(wxEVT_CHAR, &CreateReportFrame::OnChar, this);

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

	LOG(INFO) << "Done creating CreateReportFrame.";
}

void CreateReportFrame::OnClose(wxCloseEvent& event) {
	google::ShutdownGoogleLogging();
	Destroy();
}

void CreateReportFrame::OnChar(wxKeyEvent& event)
{
	if (event.GetKeyCode() == WXK_TAB)
	{
		
		wxWindow* focusWin = wxWindow::FindFocus();
		if (focusWin == txtName)
			txtCompany->SetFocus();
		else if (focusWin == txtCompany)
			txtAddress->SetFocus();
		else if (focusWin == txtAddress)
			txtPostcode->SetFocus();
		else if (focusWin == txtPostcode)
			txtPhone->SetFocus();
		else if (focusWin == txtPhone)
			txtEmail->SetFocus();
		else if (focusWin == txtEmail)
			txtDate->SetFocus();
		return;
	}
	event.Skip();
}

void CreateReportFrame::OnSubmitButtonClick(wxCommandEvent& event) {
	std::string name = txtName->GetValue().ToStdString();
	std::string company = txtCompany->GetValue().ToStdString();
	std::string address = txtAddress->GetValue().ToStdString();
	std::string postcode = txtPostcode->GetValue().ToStdString();
	std::string phone = txtPhone->GetValue().ToStdString();
	std::string email = txtEmail->GetValue().ToStdString();
	std::string date = txtDate->GetValue().ToStdString();

	createNewReport(
		name,
		company,
		address,
		postcode,
		phone,
		email,
		date
	);

	ReportItemTableFrame* reportItemTableFrame = new ReportItemTableFrame("Items added", wxPoint(550, 50), wxSize(600, 400));
	reportItemTableFrame->Show(true);

	ReportEditorFrame* reportEditorFrame = new ReportEditorFrame("Report Editor", wxPoint(50, 50), wxSize(450, 525));
	reportEditorFrame->Show(true);

	this->Show(false);
}


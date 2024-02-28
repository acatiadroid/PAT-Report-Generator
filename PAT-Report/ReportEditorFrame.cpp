#include "ReportEditorFrame.h"
#include "ReportItemTableFrame.h"

#include <wx/msgdlg.h>
#include <glog/logging.h>

wxBEGIN_EVENT_TABLE(ReportEditorFrame, wxFrame)
EVT_BUTTON(wxID_ANY, ReportEditorFrame::OnSubmitButtonClick)
wxEND_EVENT_TABLE()

ReportEditorFrame::ReportEditorFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
	: wxFrame(nullptr, wxID_ANY, title, pos, size) {
	
	LOG(INFO) << "Opened ReportEditorFrame Window. Constructing widgets...";

	lblApplianceDesc = new wxStaticText(this, wxID_ANY, "Appliance Description/Make and Model:");
	txtApplianceDesc = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);

	lblLocation = new wxStaticText(this, wxID_ANY, "Location:");
	txtLocation = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);

	lblRetestDate = new wxStaticText(this, wxID_ANY, "Retest Date:");
	txtRetestDate = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);

	lblVoltageRating = new wxStaticText(this, wxID_ANY, "Voltage Rating:");
	txtVoltageRating = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);

	lblClass = new wxStaticText(this, wxID_ANY, "Class:");
	txtClass = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);

	lblVisualCheck = new wxStaticText(this, wxID_ANY, "Visual Check:");
	txtVisualCheck = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);

	lblTestResults = new wxStaticText(this, wxID_ANY, "Test Results:");
	txtTestResults = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);

	lblContinuedUse = new wxStaticText(this, wxID_ANY, "Suitability for continued use:");
	txtContinuedUse = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);

	lblInitials = new wxStaticText(this, wxID_ANY, "Initials:");
	txtInitials = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);

	lblNotes = new wxStaticText(this, wxID_ANY, "Notes:");
	txtNotes = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);

	btnSubmit = new wxButton(this, wxID_ANY, "Submit");
	btnSubmit->Bind(wxEVT_BUTTON, &ReportEditorFrame::OnSubmitButtonClick, this);

	txtApplianceDesc->Bind(wxEVT_CHAR, &ReportEditorFrame::OnChar, this);
	txtLocation->Bind(wxEVT_CHAR, &ReportEditorFrame::OnChar, this);
	txtRetestDate->Bind(wxEVT_CHAR, &ReportEditorFrame::OnChar, this);
	txtVoltageRating->Bind(wxEVT_CHAR, &ReportEditorFrame::OnChar, this);
	txtClass->Bind(wxEVT_CHAR, &ReportEditorFrame::OnChar, this);
	txtVisualCheck->Bind(wxEVT_CHAR, &ReportEditorFrame::OnChar, this);
	txtTestResults->Bind(wxEVT_CHAR, &ReportEditorFrame::OnChar, this);
	txtContinuedUse->Bind(wxEVT_CHAR, &ReportEditorFrame::OnChar, this);
	txtInitials->Bind(wxEVT_CHAR, &ReportEditorFrame::OnChar, this);
	txtNotes->Bind(wxEVT_CHAR, &ReportEditorFrame::OnChar, this);

	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* rowSizer1 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* rowSizer2 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* rowSizer3 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* rowSizer4 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* rowSizer5 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* rowSizer6 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* rowSizer7 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* rowSizer8 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* rowSizer9 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* rowSizer10 = new wxBoxSizer(wxHORIZONTAL);

	rowSizer1->Add(lblApplianceDesc, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);
	rowSizer1->Add(txtApplianceDesc, 1, wxEXPAND | wxALL, 5);

	rowSizer2->Add(lblLocation, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);
	rowSizer2->Add(txtLocation, 1, wxEXPAND | wxALL, 5);

	rowSizer3->Add(lblRetestDate, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);
	rowSizer3->Add(txtRetestDate, 1, wxEXPAND | wxALL, 5);

	rowSizer4->Add(lblVoltageRating, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);
	rowSizer4->Add(txtVoltageRating, 1, wxEXPAND | wxALL, 5);

	rowSizer5->Add(lblClass, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);
	rowSizer5->Add(txtClass, 1, wxEXPAND | wxALL, 5);

	rowSizer6->Add(lblVisualCheck, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);
	rowSizer6->Add(txtVisualCheck, 1, wxEXPAND | wxALL, 5);

	rowSizer7->Add(lblTestResults, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);
	rowSizer7->Add(txtTestResults, 1, wxEXPAND | wxALL, 5);

	rowSizer8->Add(lblContinuedUse, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);
	rowSizer8->Add(txtContinuedUse, 1, wxEXPAND | wxALL, 5);

	rowSizer9->Add(lblInitials, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);
	rowSizer9->Add(txtInitials, 1, wxEXPAND | wxALL, 5);

	rowSizer10->Add(lblNotes, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);
	rowSizer10->Add(txtNotes, 1, wxEXPAND | wxALL, 5);

	mainSizer->Add(rowSizer1, 0, wxEXPAND | wxALL, 5);
	mainSizer->Add(rowSizer2, 0, wxEXPAND | wxALL, 5);
	mainSizer->Add(rowSizer3, 0, wxEXPAND | wxALL, 5);
	mainSizer->Add(rowSizer4, 0, wxEXPAND | wxALL, 5);
	mainSizer->Add(rowSizer5, 0, wxEXPAND | wxALL, 5);
	mainSizer->Add(rowSizer6, 0, wxEXPAND | wxALL, 5);
	mainSizer->Add(rowSizer7, 0, wxEXPAND | wxALL, 5);
	mainSizer->Add(rowSizer8, 0, wxEXPAND | wxALL, 5);
	mainSizer->Add(rowSizer9, 0, wxEXPAND | wxALL, 5);
	mainSizer->Add(rowSizer10, 0, wxEXPAND | wxALL, 5);

	mainSizer->Add(btnSubmit, 0, wxALIGN_CENTER | wxALL, 10);

	SetSizer(mainSizer);
	Bind(wxEVT_CLOSE_WINDOW, &ReportEditorFrame::OnClose, this);

	LOG(INFO) << "Done creating ReportEditorFrame.";

	ReportItemTableFrame* reportItemTableFrame = new ReportItemTableFrame("Items added", wxPoint(500, 50), wxSize(600, 400));
	reportItemTableFrame->Show(true);

}

void ReportEditorFrame::OnSubmitButtonClick(wxCommandEvent& event) {

}


void ReportEditorFrame::OnClose(wxCloseEvent& event) {
	google::ShutdownGoogleLogging();
	Destroy();
}

void ReportEditorFrame::OnChar(wxKeyEvent& event)
{
	if (event.GetKeyCode() == WXK_TAB)
	{

		wxWindow* focusWin = wxWindow::FindFocus();
		if (focusWin == txtApplianceDesc)
			txtLocation->SetFocus();
		else if (focusWin == txtLocation)
			txtRetestDate->SetFocus();
		else if (focusWin == txtRetestDate)
			txtVoltageRating->SetFocus();
		else if (focusWin == txtVoltageRating)
			txtClass->SetFocus();
		else if (focusWin == txtClass)
			txtVisualCheck->SetFocus();
		else if (focusWin == txtVisualCheck)
			txtContinuedUse->SetFocus();
		else if (focusWin == txtContinuedUse)
			txtInitials->SetFocus();
		else if (focusWin == txtInitials) {
			txtNotes->SetFocus();
		}

		return;
	}
	event.Skip();
}
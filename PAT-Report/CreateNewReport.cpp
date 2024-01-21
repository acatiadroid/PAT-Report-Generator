#include "CreateReportFrame.h"

#include <wx/msgdlg.h>

wxBEGIN_EVENT_TABLE(CreateReportFrame, wxFrame)
EVT_BUTTON(wxID_ANY, CreateReportFrame::SaveNewReport)
wxEND_EVENT_TABLE()

CreateReportFrame::CreateReportFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
	: wxFrame(nullptr, wxID_ANY, title, pos, size) {

	wxStaticText* lblName = new wxStaticText(this, wxID_ANY, "Customer(s):", wxPoint(20, 20), wxSize(300, 300));
	wxStaticText* lblCompany = new wxStaticText(this, wxID_ANY, "Company:", wxPoint(20, 60), wxSize(300, 300));
	wxStaticText* lblAddress = new wxStaticText(this, wxID_ANY, "Address:", wxPoint(20, 100), wxSize(300, 300));
	wxStaticText* lblPostcode = new wxStaticText(this, wxID_ANY, "Postcode:", wxPoint(20, 140), wxSize(300, 300));
	wxStaticText* lblPhone = new wxStaticText(this, wxID_ANY, "Phone:", wxPoint(20, 180), wxSize(300, 300));
	wxStaticText* lblEmail = new wxStaticText(this, wxID_ANY, "Email:", wxPoint(20, 240), wxSize(300, 300));
	wxStaticText* lblDate = new wxStaticText(this, wxID_ANY, "Date:", wxPoint(20, 280), wxSize(300, 300));
	
	wxTextCtrl* txtName = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxPoint(100, 20), wxSize(140, 25), 0);
	wxTextCtrl* txtCustomer = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxPoint(100, 60), wxSize(140, 25), 0);

	txtName->Bind(wxEVT_SET_FOCUS, &CreateReportFrame::OnTextCtrlFocus, this);
	txtCustomer->Bind(wxEVT_SET_FOCUS, &CreateReportFrame::OnTextCtrlFocus, this);

	Bind(wxEVT_CLOSE_WINDOW, &CreateReportFrame::OnClose, this);
}

void CreateReportFrame::OnClose(wxCloseEvent& event) {
	Destroy();
}

void CreateReportFrame::OnTextCtrlFocus(wxFocusEvent& event) {
	wxTextCtrl* textCtrl = wxDynamicCast(event.GetEventObject(), wxTextCtrl);

	if (textCtrl) {
		textCtrl->SetSelection(-1, -1);
	}

	event.Skip();
}

void CreateReportFrame::SaveNewReport(wxCommandEvent& event) {
	wxMessageBox("Button Clicked", "Message", wxOK | wxICON_INFORMATION);
}

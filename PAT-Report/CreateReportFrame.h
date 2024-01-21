#ifndef CREATEREPORTFRAME_H
#define CREATEREPORTFRAME_H

#include <wx/wx.h>

class CreateReportFrame : public wxFrame {
public:
	CreateReportFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

	void OnClose(wxCloseEvent& event);
	void OnTextCtrlFocus(wxFocusEvent& event);
	void SaveNewReport(wxCommandEvent& event);

private:
	wxStaticText* lblName;
	wxStaticText* lblCompany;
	wxStaticText* lblAddress;
	wxStaticText* lblPostcode;
	wxStaticText* lblPhone;
	wxStaticText* lblEmail;
	wxStaticText* lblDate;

	wxTextCtrl* txtName;
	wxTextCtrl* txtCustomer;

	wxDECLARE_EVENT_TABLE();
};

#endif
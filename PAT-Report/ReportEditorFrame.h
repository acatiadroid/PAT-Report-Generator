#ifndef REPORTEDITORFRAME_H
#define REPORTEDITORFRAME_H
#define GLOG_NO_ABBREVIATED_SEVERITIES

#include <wx/wx.h>
#include <glog/logging.h>

class ReportEditorFrame : public wxFrame {
public:
	ReportEditorFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

	void OnClose(wxCloseEvent& event);
	void OnChar(wxKeyEvent& event);
	void OnSubmitButtonClick(wxCommandEvent& event);

private:
	wxStaticText* lblApplianceDesc;
	wxStaticText* lblLocation;
	wxStaticText* lblRetestDate;
	wxStaticText* lblVoltageRating;
	wxStaticText* lblClass;
	wxStaticText* lblVisualCheck;
	wxStaticText* lblTestResults;
	wxStaticText* lblContinuedUse;
	wxStaticText* lblInitials;
	wxStaticText* lblNotes;

	wxTextCtrl* txtApplianceDesc;
	wxTextCtrl* txtLocation;
	wxTextCtrl* txtRetestDate;
	wxTextCtrl* txtVoltageRating;
	wxTextCtrl* txtClass;
	wxTextCtrl* txtVisualCheck;
	wxTextCtrl* txtTestResults;
	wxTextCtrl* txtContinuedUse;
	wxTextCtrl* txtInitials;
	wxTextCtrl* txtNotes;


	wxDECLARE_EVENT_TABLE();
};

#endif

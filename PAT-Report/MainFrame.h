#ifndef MAINFRAME_H
#define MAINFRAME_H
#define GLOG_NO_ABBREVIATED_SEVERITIES

#include <wx/wx.h>


class MainFrame : public wxFrame {
public:
	MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

	void OnClose(wxCloseEvent& event);
	void OnButtonClicked(wxCommandEvent& event);

private:
	wxButton* btnCreateNewReport;
	wxButton* btnOpenExistingReport;

	wxDECLARE_EVENT_TABLE();
};

#endif
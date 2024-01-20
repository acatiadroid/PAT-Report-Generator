#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <wx/wx.h>


class MainFrame : public wxFrame {
public:
	MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

	void OnButtonClicked(wxCommandEvent& event);

private:
	wxButton* m_button;
	wxDECLARE_EVENT_TABLE();
};

#endif
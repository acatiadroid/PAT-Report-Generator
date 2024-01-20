#include "MainFrame.h"

#include <wx/msgdlg.h>

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
EVT_BUTTON(wxID_ANY, MainFrame::OnButtonClicked)
wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
	: wxFrame(nullptr, wxID_ANY, title, pos, size) {

	m_button = new wxButton(this, wxID_ANY, "Click me!", wxPoint(10, 10), wxSize(150, 30));
}

void MainFrame::OnButtonClicked(wxCommandEvent& event) {
	wxMessageBox("Button Clicked", "Message", wxOK | wxICON_INFORMATION);
}
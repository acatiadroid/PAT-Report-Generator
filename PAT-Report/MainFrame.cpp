#include "MainFrame.h"
#include "CreateReportFrame.h"

#include <wx/msgdlg.h>
#include <glog/logging.h>

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
EVT_BUTTON(wxID_ANY, MainFrame::OnButtonClicked)
wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
	: wxFrame(nullptr, wxID_ANY, title, pos, size) {

	btnCreateNewReport = new wxButton(this, wxID_ANY, "Create new report", wxPoint(10, 10), wxSize(300, 50));
	btnOpenExistingReport = new wxButton(this, wxID_ANY, "Open existing report", wxPoint(10, 70), wxSize(300, 50));
	
	Bind(wxEVT_CLOSE_WINDOW, &MainFrame::OnClose, this);
}

void MainFrame::OnClose(wxCloseEvent& event) {
	Destroy();
	google::ShutdownGoogleLogging();

}
void MainFrame::OnButtonClicked(wxCommandEvent& event) {
	CreateReportFrame* frame = new CreateReportFrame("Create new report", wxPoint(50, 50), wxSize(340, 400));
	frame->Show(true);
	this->Show(false);
}
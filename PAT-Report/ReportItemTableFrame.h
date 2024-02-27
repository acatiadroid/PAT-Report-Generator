#ifndef REPORTITEMTABLEFRAME_H
#define REPORTITEMTABLEFRAME_H
#define GLOG_NO_ABBREVIATED_SEVERITIES

#include <wx/wx.h>
#include <wx/grid.h>
#include <glog/logging.h>

class ReportItemTableFrame : public wxFrame {
public:
	ReportItemTableFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

	void OnClose(wxCloseEvent& event);

private:
	wxGrid* grid;
	wxBoxSizer* sizer;
};

#endif
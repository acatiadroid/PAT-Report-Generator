#include "ReportItemTableFrame.h"

#include <wx/msgdlg.h>
#include <wx/grid.h>
#include <glog/logging.h>

ReportItemTableFrame::ReportItemTableFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
	: wxFrame(nullptr, wxID_ANY, title, pos, size) {

	LOG(INFO) << "Created Report Item Table window.";

	grid = new wxGrid(this, wxID_ANY);
	grid->CreateGrid(10, 10);
	grid->SetCellValue(1, 1, "test");

	
	sizer = new wxBoxSizer(wxVERTICAL);

	sizer->Add(grid, 1, wxEXPAND | wxALL, 5);

	SetSizer(sizer);

}
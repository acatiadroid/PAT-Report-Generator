#include "App.h"
#include "MainFrame.h"

wxIMPLEMENT_APP(App);

bool App::OnInit() {
	MainFrame* frame = new MainFrame("PAT Report Generator", wxPoint(50, 50), wxSize(340, 300));

	frame->Show(true);

	return true;
}
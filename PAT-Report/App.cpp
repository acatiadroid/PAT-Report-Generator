#include "App.h"
#include "MainFrame.h"

#include <glog/logging.h>

wxIMPLEMENT_APP(App);

bool App::OnInit() {
	FLAGS_log_dir = "C:/Users/lukeh/Documents/c++/PAT-Report/Data/Logging";
	google::InitGoogleLogging(argv[0]);

	LOG(INFO) << "Starting window.";

	MainFrame* frame = new MainFrame("PAT Report Generator", wxPoint(50, 50), wxSize(340, 300));

	frame->Show(true);

	return true;
}

int App::OnExit() {
	google::ShutdownGoogleLogging();

	return wxApp::OnExit();
}
#include "App.h"
#include "MainFrame.h"
#include "XmlFileIndexParser.h"
#include "XmlProjectSettingsParser.h"

#include <glog/logging.h>

IMPLEMENT_APP(App);

bool App::OnInit() {
	FLAGS_log_dir = "C:/Users/lukeh/Documents/c++/PAT-Report/Data/Logging";
	google::InitGoogleLogging(argv[0]);

	LOG(INFO) << "Verifying file integrity...";
	
	checkProjectSettingsExists();
	checkFileIndexExists();

	LOG(INFO) << "Done. Starting app...";

	MainFrame* frame = new MainFrame("PAT Report Generator", wxPoint(50, 50), wxSize(340, 300));

	frame->Show(true);

	return true;
}

int App::OnExit() {
	google::ShutdownGoogleLogging();

	return wxApp::OnExit();
}
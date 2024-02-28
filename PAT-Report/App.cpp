#include "App.h"
#include "MainFrame.h"
#include "XmlFileIndexParser.h"
#include "XmlProjectSettingsParser.h"

#include <glog/logging.h>
#include <filesystem>
#include <string>

IMPLEMENT_APP(App);

bool App::OnInit() {

	std::filesystem::path workingDir = std::filesystem::current_path();
	std::filesystem::path filePath;

	bool projectSettingsExists = checkProjectSettingsExists(workingDir);

	if (!projectSettingsExists) {
		LOG(INFO) << "Creating project settings file because it doesn't exist.";
		if (!createProjectSettingsFile()) {
			LOG(FATAL) << "Unable to create project settings file.";
		}
	}

	FLAGS_log_dir = getLoggingDirPath().string();
	google::InitGoogleLogging(argv[0]);

	LOG(INFO) << "Verifying file integrity...";

	checkFileIndexExists();

	LOG(INFO) << "Done. Starting app...";

	MainFrame* frame = new MainFrame("PAT Report Generator", wxPoint(50, 50), wxSize(340, 300));

	frame->SetIcon(wxIcon("C:/Users/lukeh/Documents/c++/PAT-Report/Data/icon.ico"));
	frame->Show(true);

	return true;
}

int App::OnExit() {
	google::ShutdownGoogleLogging();

	return wxApp::OnExit();
}
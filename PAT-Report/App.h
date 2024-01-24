#ifndef APP_H
#define APP_H
#define GLOG_NO_ABBREVIATED_SEVERITIES

#include <wx/wx.h>
#include <glog/logging.h>

class App : public wxApp {
public:
	virtual bool OnInit();
	virtual int OnExit();
};

#endif
#pragma once
#include "ViewWindow.h"

class ViewSystem {
private:
public:
	std::vector<ViewWindow> m_windowset;
	ViewWindow* m_DEFAULT_WINDOW;
	ViewSystem();
	int getwindownum() const;
	std::vector<ViewWindow>::iterator getWindow(const char* name) ;
	std::vector<ViewWindow>::iterator getnullwindow() ;
	bool deletewindow(std::vector<ViewWindow>::iterator &temp);
	ViewWindow* getWINDOW() const;
	bool setWINDOW(std::vector<ViewWindow>::iterator vw, const bool &v = true);
	bool attach(const ViewWindow &vw);
	void draw();
	virtual ~ViewSystem();
};
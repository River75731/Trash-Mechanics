#pragma once
#include "ViewWindow.h"

class ViewSystem {
private:
	std::vector<ViewWindow> m_windowset;
	ViewWindow m_DEFAULT_WINDOW;
public:
	ViewSystem();
	int getwindownum() const;
	std::vector<ViewWindow>::iterator getWindow(const std::string &name);
	std::vector<ViewWindow>::iterator getnullwindow();
	bool deletewindow(std::vector<ViewWindow>::const_iterator &temp);
	ViewWindow getWINDOW() const;
	bool setWINDOW(const ViewWindow &vw);
	bool attach(const ViewWindow &vw);
	void draw();
	virtual ~ViewSystem();
};
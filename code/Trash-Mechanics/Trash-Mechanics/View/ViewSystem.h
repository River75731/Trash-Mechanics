#pragma once
#include "ViewWindow.h"

class ViewSystem {
private:
	std::vector<ViewWindow> m_windowset;
	ViewWindow m_DEFAULT_WINDOW;
public:
	ViewSystem();
	int getwindownum() const;
	ViewWindow* getWindow(const std::string &name);
	ViewWindow getWINDOW() const;
	bool setWINDOW(const ViewWindow &vw);
	bool attach(const ViewWindow &vw);
	void draw();
	virtual ~ViewSystem();
};
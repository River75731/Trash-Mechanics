#pragma once
#include "ViewWindow.h"

class ViewSystem {
private:
	std::vector<ViewWindow> windowset;
	ViewWindow DEFAULT_WINDOW;
public:
	ViewSystem();
	int getwindownum() const;
	ViewWindow getWINDOW() const;
	bool setWINDOW(const ViewWindow &vw);
	bool attach(const ViewWindow &vw);
	virtual ~ViewSystem();
};
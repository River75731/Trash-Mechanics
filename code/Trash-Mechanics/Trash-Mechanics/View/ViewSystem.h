#pragma once
#include "ViewWindow.h"

class ViewSystem {
private:
	std::vector<ViewWindow*> m_windowset;
	ViewWindow* m_DEFAULT_WINDOW;
public:
	ViewSystem();
	int getwindownum() const;
	ViewWindow* getWindow(const char* name) ;
	bool deletewindow(ViewWindow* &temp); 
	ViewWindow* getWINDOW() const;
	bool setWINDOW(ViewWindow* vw);
	bool attach(ViewWindow* vw);
	void drawSystem();
	virtual ~ViewSystem();
};
#pragma once
#include "ViewShape.h"

#include<FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <vector>
#include <string>

#define DEFAULT_TOPLEFT ViewPoint(Fl::w()/4,Fl::h()/4)
#define DEFAULT_WINWIDTH Fl::w()/2
#define DEFAULT_WINHEIGHT Fl::h()/2
#define DEFAULT_WINNAME "New Page"
#define DEFAULT_WINCOLOR FL_WHITE

class ViewWindow :public Fl_Double_Window {
private:
	std::vector<ViewShape*> m_shapeset;
public:
	ViewWindow(const ViewWindow &vw);
	ViewWindow(const ViewPoint &tl, const int &w = DEFAULT_WINWIDTH, const int &h = DEFAULT_WINHEIGHT, const std::string &n = DEFAULT_WINNAME, const Fl_Color &c = DEFAULT_WINCOLOR);
	ViewWindow(const Vec &tl, const int &w = DEFAULT_WINWIDTH, const int &h = DEFAULT_WINHEIGHT, const std::string &n = DEFAULT_WINNAME, const Fl_Color &c = DEFAULT_WINCOLOR);
	ViewWindow(const int &x = DEFAULT_TOPLEFT.getintX(), const int &y = DEFAULT_TOPLEFT.getintY(), const int &w = DEFAULT_WINWIDTH, const int &h = DEFAULT_WINHEIGHT, const std::string &n = DEFAULT_WINNAME, const Fl_Color &c = DEFAULT_WINCOLOR);
	ViewWindow& operator = (const ViewWindow &vw);
	std::vector<ViewShape*> getshapeset() const;
	int gettopleftX() const;
	int gettopleftY() const;
	int getwidth() const;
	int getheight() const;
	const char* getname() const;
	Fl_Color getcolor() const;
	bool setshapeset(const std::vector<ViewShape*> &ss);
	bool setsize(const Vec &tl, const int &w, const int &h);
	bool setsize(const int &x, const int &y, const int &w, const int &h);
	bool setname(const char* n);
	bool setcolor(const Fl_Color &c);
	void draw();
	void attach(ViewShape &vs);
	virtual ~ViewWindow();
};
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
#define DEFAULT_WINVISIBLE true

class ViewWindow :public Fl_Double_Window {
private:
	static ViewPoint m_DEFAULT_TOPLEFT;
	static int m_DEFAULT_WINWIDTH;
	static int m_DEFAULT_WINHEIGHT;
	static std::string m_DEFAULT_WINNAME;
	static Fl_Color m_DEFAULT_WINCOLOR;
	static bool m_DEFAULT_WINVISIBLE;
	//static ViewWindow m_DEFAULT_WINDOW;
	//static int m_WINDOWNUM;
	bool m_winvisible;
	std::vector<ViewShape*> m_shapeset;
public:
	ViewWindow(const ViewWindow &vw);
	ViewWindow(const ViewPoint &tl, const int &w = m_DEFAULT_WINWIDTH, const int &h = m_DEFAULT_WINHEIGHT, const bool &v=m_DEFAULT_WINVISIBLE, const std::string &n = m_DEFAULT_WINNAME, const Fl_Color &c = m_DEFAULT_WINCOLOR);
	ViewWindow(const Vec &tl, const int &w = m_DEFAULT_WINWIDTH, const int &h = m_DEFAULT_WINHEIGHT, const bool &v=m_DEFAULT_WINVISIBLE, const std::string &n = m_DEFAULT_WINNAME, const Fl_Color &c = m_DEFAULT_WINCOLOR);
	ViewWindow(const int &x = m_DEFAULT_TOPLEFT.getintX(), const int &y = m_DEFAULT_TOPLEFT.getintY(), const int &w = m_DEFAULT_WINWIDTH, const int &h = m_DEFAULT_WINHEIGHT, const bool &v = m_DEFAULT_WINVISIBLE, const std::string &n = m_DEFAULT_WINNAME, const Fl_Color &c = m_DEFAULT_WINCOLOR);
	ViewWindow& operator = (const ViewWindow &vw);
	bool operator == (const ViewWindow &vw);
	
	std::vector<ViewShape*> getshapeset() const;
	int gettopleftX() const;
	int gettopleftY() const;
	int getwidth() const;
	int getheight() const;
	const char* getname() const;
	Fl_Color getcolor() const;
	bool getwinvisible() const;
	static ViewPoint getTOPLEFT() ;
	static int getWINWIDTH();
	static int getWINHEIGHT() ;
	static std::string getWINNAME() ;
	static Fl_Color getWINCOLOR() ;
	static bool getWINVISIBLE();

	bool setshapeset(const std::vector<ViewShape*> &ss);
	bool setsize(const Vec &tl, const int &w, const int &h);
	bool setsize(const int &x, const int &y, const int &w, const int &h);
	bool setname(const char* n);
	bool setcolor(const Fl_Color &c);
	bool setwinvisible(const bool &v);
	static bool setTOPLEFT(const int &x, const int &y);
	static bool setWINWIDTH(const int &w);
	static bool setWINHEIGHT(const int &h);
	static bool setWINNAME(const std::string &s);
	static bool setWINCOLOR(const Fl_Color &c);
	static bool setWINVISIBLE(const bool &v);
	
	bool clearshapeset();
	bool attach(ViewShape *vs);
	ViewShape* getviewshape(const int &id); //return nullptr if not exist
	bool deleteshape(ViewShape* &vs);
	void draw();
	virtual ~ViewWindow();
};
#include "ViewWindow.h"

ViewPoint ViewWindow::m_DEFAULT_TOPLEFT = DEFAULT_TOPLEFT;
int ViewWindow::m_DEFAULT_WINWIDTH = DEFAULT_WINWIDTH;
int ViewWindow::m_DEFAULT_WINHEIGHT = DEFAULT_WINHEIGHT;
std::string ViewWindow::m_DEFAULT_WINNAME = DEFAULT_WINNAME;
Fl_Color ViewWindow::m_DEFAULT_WINCOLOR = DEFAULT_WINCOLOR;

ViewWindow::ViewWindow(const ViewWindow & vw)
	:Fl_Double_Window(vw.gettopleftX(), vw.gettopleftY(), vw.getwidth(), vw.getheight(), vw.getname())
{	
	setcolor(vw.getcolor());
	clearshapeset();
	for (std::vector<ViewShape*>::const_iterator i = vw.getshapeset().begin(); i != vw.getshapeset().end(); i++)
		m_shapeset.push_back(*i);
}

ViewWindow::ViewWindow(const ViewPoint & tl, const int & w, const int & h, const std::string & n, const Fl_Color & c)
	: Fl_Double_Window(tl.getintX(), tl.getintY(), w, h, n.c_str())
{
	setcolor(c);
}

ViewWindow::ViewWindow(const Vec & tl, const int & w, const int & h, const std::string & n, const Fl_Color & c)
	: Fl_Double_Window(int(tl.getX()), int(tl.getY()), w, h, n.c_str())
{
	setcolor(c);
}

ViewWindow::ViewWindow(const int & x, const int & y, const int &w, const int & h, const std::string & n, const Fl_Color & c)
	: Fl_Double_Window(x, y, w, h, n.c_str())
{
	setcolor(c);
}

ViewWindow & ViewWindow::operator=(const ViewWindow & vw)
{
	setsize(vw.gettopleftX(), vw.gettopleftY(), vw.getwidth(), vw.getheight());
	setname(vw.getname());
	setcolor(vw.getcolor());
	clearshapeset();
	for (std::vector<ViewShape*>::const_iterator i = vw.getshapeset().begin(); i != vw.getshapeset().end(); i++)
		m_shapeset.push_back(*i);
	return *this;
}

std::vector<ViewShape*> ViewWindow::getshapeset() const
{
	return m_shapeset;
}

int ViewWindow::gettopleftX() const
{
	return x_root();
}

int ViewWindow::gettopleftY() const
{
	return y_root();
}

int ViewWindow::getwidth() const
{
	return w();
}

int ViewWindow::getheight() const
{
	return h();
}

const char * ViewWindow::getname() const
{
	return label();
}

Fl_Color ViewWindow::getcolor() const
{
	return color();
}

ViewPoint ViewWindow::getTOPLEFT() 
{
	return m_DEFAULT_TOPLEFT;
}

int ViewWindow::getWINWIDTH() 
{
	return m_DEFAULT_WINWIDTH;
}

int ViewWindow::getWINHEIGHT() 
{
	return m_DEFAULT_WINHEIGHT;
}

std::string ViewWindow::getWINNAME()
{
	return m_DEFAULT_WINNAME;
}

Fl_Color ViewWindow::getWINCOLOR() 
{
	return m_DEFAULT_WINCOLOR;
}

bool ViewWindow::setshapeset(const std::vector<ViewShape*>& ss)
{
	clearshapeset();
	ViewShape* temp;
	for (std::vector<ViewShape*>::const_iterator i = ss.begin(); i != ss.end(); i++)
	{
		temp = *i;
		m_shapeset.push_back(temp);
	}
	return true;
}

bool ViewWindow::setsize(const Vec & tl, const int & w, const int & h)
{
	resize(int(tl.getX()), int(tl.getY()), w, h);
	return true;
}

bool ViewWindow::setsize(const int & x, const int & y, const int & w, const int & h)
{
	resize(x, y, w, h);
	return true;
}

bool ViewWindow::setname(const char * n)
{
	copy_label(n);
	return true;
}

bool ViewWindow::setcolor(const Fl_Color & c)
{
	color(c);
	return true;
}

bool ViewWindow::setTOPLEFT(const int & x, const int & y)
{
	m_DEFAULT_TOPLEFT = ViewPoint(x, y);
	return true;
}

bool ViewWindow::setWINWIDTH(const int & w)
{
	m_DEFAULT_WINWIDTH = w;
	return true;
}

bool ViewWindow::setWINHEIGHT(const int & h)
{
	m_DEFAULT_WINHEIGHT = h;
	return true;
}

bool ViewWindow::setWINNAME(const std::string & s)
{
	m_DEFAULT_WINNAME = s;
	return true;
}

bool ViewWindow::setWINCOLOR(const Fl_Color & c)
{
	m_DEFAULT_WINCOLOR = c;
	return true;
}

bool ViewWindow::clearshapeset()
{
	for (std::vector<ViewShape*>::iterator i = m_shapeset.begin(); i != m_shapeset.end(); i++) free(*i);
	m_shapeset.clear();
	return true;
}

void ViewWindow::draw()
{
	Fl_Double_Window::draw();
	for (std::vector<ViewShape*>::iterator i = m_shapeset.begin(); i != m_shapeset.end(); i++)
		if ((*i)->getvisible()) (*i)->drawShape();
}

void ViewWindow::attach(ViewShape &vs)
{
	m_shapeset.push_back(&vs);
}

ViewWindow::~ViewWindow()
{
	return;
}








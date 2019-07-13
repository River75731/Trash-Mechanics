#include "ViewWindow.h"

ViewPoint ViewWindow::m_DEFAULT_TOPLEFT = DEFAULT_TOPLEFT;
int ViewWindow::m_DEFAULT_WINWIDTH = DEFAULT_WINWIDTH;
int ViewWindow::m_DEFAULT_WINHEIGHT = DEFAULT_WINHEIGHT;
std::string ViewWindow::m_DEFAULT_WINNAME = DEFAULT_WINNAME;
Fl_Color ViewWindow::m_DEFAULT_WINCOLOR = DEFAULT_WINCOLOR;
bool ViewWindow::m_DEFAULT_WINVISIBLE = DEFAULT_WINVISIBLE;

//ViewWindow ViewWindow::m_DEFAULT_WINDOW ;
//int ViewWindow::m_WINDOWNUM = 0;

ViewWindow::ViewWindow(const ViewWindow & vw)
	:Fl_Double_Window(vw.gettopleftX(), vw.gettopleftY(), vw.getwidth(), vw.getheight(), vw.getname())
{	
	setwinvisible(vw.getwinvisible());
	setcolor(vw.getcolor());
	copy_label(vw.getname());
	clearshapeset();
	std::vector<ViewShape*> temp = vw.getshapeset();
	if (temp.empty()) return;
	for (std::vector<ViewShape*>::const_iterator i = temp.begin(); i != temp.end(); i++)
		m_shapeset.push_back(*i);
//	m_WINDOWNUM++;
//	m_DEFAULT_WINDOW = *this;
}

ViewWindow::ViewWindow(const ViewPoint & tl, const int & w, const int & h, const bool &v, const std::string & n, const Fl_Color & c)
	: Fl_Double_Window(tl.getintX(), tl.getintY(), w, h, n.c_str())
{
	copy_label(n.c_str());
	setcolor(c);
	setwinvisible(v);
//	m_WINDOWNUM++;
//	m_DEFAULT_WINDOW = *this;
}

ViewWindow::ViewWindow(const Vec & tl, const int & w, const int & h,  const bool &v, const std::string & n, const Fl_Color & c)
	: Fl_Double_Window(int(tl.getX()), int(tl.getY()), w, h, n.c_str()), m_shapeset()
{
	copy_label(n.c_str());
	setcolor(c);
	setwinvisible(v);
//	m_WINDOWNUM++;
//	m_DEFAULT_WINDOW = *this;
}

ViewWindow::ViewWindow(const int & x, const int & y, const int &w, const int & h, const bool &v, const std::string & n, const Fl_Color & c)
	: Fl_Double_Window(x, y, w, h, n.c_str())
{
	copy_label(n.c_str());
	setcolor(c);
	setwinvisible(v);
//	m_WINDOWNUM++;
//	m_DEFAULT_WINDOW = *this;
}

ViewWindow & ViewWindow::operator=(const ViewWindow & vw)
{
	copy_label(vw.getname());
	setsize(vw.gettopleftX(), vw.gettopleftY(), vw.getwidth(), vw.getheight());
	setname(vw.getname());
	setcolor(vw.getcolor());
	setwinvisible(vw.getwinvisible());
	clearshapeset();
	std::vector<ViewShape*> temp = vw.getshapeset();
	if (temp.empty()) return *this;
	for (std::vector<ViewShape*>::const_iterator i = temp.begin(); i != temp.end(); i++)
		m_shapeset.push_back(*i);
	return *this;
}

bool ViewWindow::operator==(const ViewWindow & vw)
{
	if (gettopleftX() != vw.gettopleftX()) return false;
	if (gettopleftY() != vw.gettopleftY()) return false;
	if (getwidth() != vw.getwidth()) return false;
	if (getheight() != vw.getheight()) return false;
	if (strcmp(getname(), vw.getname())) return false;
	if (getcolor() != vw.getcolor()) return false;
	if (getwinvisible() != vw.getwinvisible()) return false;
	return true;
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

bool ViewWindow::getwinvisible() const
{
	return m_winvisible;
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

bool ViewWindow::getWINVISIBLE()
{
	return m_DEFAULT_WINVISIBLE;
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

bool ViewWindow::setwinvisible(const bool & v)
{
	m_winvisible = v;
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

bool ViewWindow::setWINVISIBLE(const bool & v)
{
	m_DEFAULT_WINVISIBLE = v;
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

bool ViewWindow::attach(ViewShape &vs)
{
	m_shapeset.push_back(&vs);
	return true;
}

std::vector<ViewShape*>::const_iterator ViewWindow::getshape(const int & id) const
{
	for (std::vector<ViewShape*>::const_iterator i = m_shapeset.begin(); i != m_shapeset.end(); i++)
		if ((*i)->getid() == id) return i;
	return m_shapeset.end();
}

std::vector<ViewShape*>::const_iterator ViewWindow::getnullshape()
{
	return m_shapeset.end();
}

bool ViewWindow::deleteshape(std::vector<ViewShape*>::const_iterator &temp)
{
	m_shapeset.erase(temp);
	return true;
}

ViewWindow::~ViewWindow()
{
//	m_WINDOWNUM--;
	clearshapeset();
	return;
}








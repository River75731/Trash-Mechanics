#include "MyFLTK.h"

MyPoint::MyPoint()
{
	m_X = m_Y = 0;
}

MyPoint::MyPoint(const int &x, const int &y)
{
	m_X = x;
	m_Y = y;
}

int MyPoint::getX() const
{
	return m_X;
}

int MyPoint::getY() const
{
	return m_Y;
}

bool MyPoint::setX(const int &x)
{
	m_X = x;
	return true;
}

bool MyPoint::setY(const int &y)
{
	m_Y = y;
	return true;
}

bool MyPoint::setXY(const int & x, const int & y)
{
	m_X = x;
	m_Y = y;
	return true;
}


MyPoint::~MyPoint()
{
	return;
}


MyShape::MyShape(const int & lw, const Fl_Color & ec, const Fl_Color & fc)
{
	m_linewidth = lw;
	m_edgecolor = ec;
	m_fillcolor = fc;
	return;
}

void MyShape::add(const MyPoint & p)
{
	Pointset.push_back(p);
	return;
}

MyShape::~MyShape()
{
	return;
}

void MyShape::draw()
{
	return;
}

MySegment::MySegment(const MyPoint & p1, const MyPoint & p2, const Fl_Color & lw, const Fl_Color & lc)
	:MyShape(lw, lc, lc)
{
	add(p1);
	add(p2);
	return;
}

void MySegment::draw()
{
	fl_color(m_edgecolor);
	fl_line_style(FL_SOLID, m_linewidth);
	fl_line(Pointset.begin()->getX(), Pointset.begin()->getY(), (Pointset.begin() + 1)->getX(), (Pointset.begin() + 1)->getY());
	return;
}

MySegment::~MySegment()
{
	return;
}

MyPolygon::MyPolygon(const std::vector<MyPoint>& ps, const int & lw, const Fl_Color & ec, const Fl_Color & fc)
	:MyShape(lw, ec, fc)
{
	for (std::vector<MyPoint>::const_iterator i = ps.begin(); i != ps.end(); i++)
		Pointset.push_back(*i);
	return;
}

void MyPolygon::draw()
{
	fl_color(m_fillcolor);
	fl_begin_polygon();
	for (std::vector<MyPoint>::iterator i = Pointset.begin(); i != Pointset.end(); i++)
		fl_vertex(double(i->getX()), double(i->getY()));
	fl_end_polygon();
	fl_color(m_edgecolor);
	fl_line_style(FL_SOLID, m_linewidth);
	for (std::vector<MyPoint>::iterator i = Pointset.begin(); i < Pointset.end() - 2; i++)
		fl_line(i->getX(), i->getY(), (i + 1)->getX(), (i + 1)->getY());
	return;
}


MyPolygon::~MyPolygon()
{
	return;
}


MyWindow::MyWindow() :Fl_Double_Window(Fl::w() / 4, Fl::h() / 4, Fl:: w() / 2, Fl:: h() / 2, "New Page")
{
	MyWindow::color(FL_BLACK);
}

MyWindow::MyWindow(MyPoint topleft, const int &width, const int &height, const std::string &name, const Fl_Color &color)
	:Fl_Double_Window(topleft.getX(), topleft.getY(), width, height, name.c_str())
{
	MyWindow::color(color);
	show();
}

void MyWindow::draw()
{
	Fl_Double_Window::draw();
	for (std::vector<MyShape*>::iterator i = Shapeset.begin(); i != Shapeset.end(); i++) (*i)->draw();
	//for (int i = 0; i < Shapeset.size(); i++) Shapeset[i]->draw();
	return;
}

void MyWindow::add(MyShape & s)
{
	Shapeset.push_back(&s);
	return;
}

MyWindow::~MyWindow()
{
	return;
}
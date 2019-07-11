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

MyPolygon::MyPolygon(const int & lw, const Fl_Color & ec, const Fl_Color & fc)
	:MyShape(lw,ec,fc)
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
	for (std::vector<MyPoint>::iterator i = Pointset.begin(); i < Pointset.end() - 1; i++)
		fl_line(i->getX(), i->getY(), (i + 1)->getX(), (i + 1)->getY());
	fl_line((Pointset.end() - 1)->getX(), (Pointset.end() - 1)->getY(), Pointset.begin()->getX(), Pointset.begin()->getY());
	return;
}


MyPolygon::~MyPolygon()
{
	return;
}


MyWindow::MyWindow() :Fl_Double_Window(Fl::w() / 4, Fl::h() / 4, Fl:: w() / 2, Fl:: h() / 2, "New Page")
{
	MyWindow::color(FL_WHITE);
}

MyWindow::MyWindow(MyPoint topleft, const int &width, const int &height, const std::string &name, const Fl_Color &color)
	:Fl_Double_Window(topleft.getX(), topleft.getY(), width, height, name.c_str())
{
	MyWindow::color(color);
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

/*
MyImage::MyImage(const MyPoint & tl, const int & w, const int & h, const std::string path, const int & lw, const Fl_Color & ec, const Fl_Color & fc)
	:MyShape(lw, ec, fc), m_png(path.c_str())
{
	m_width = w;
	m_height = h;
	m_index = Imagenum;
	Imagenum++;
	return;
}

void MyImage::draw()
{
	m_box[m_index].image(m_png);
	m_box[m_index].resize(m_topleft.getX(), m_topleft.getY(), m_width, m_height);
	m_box[m_index].show();
}


void MyImage::relocate(const MyPoint & tl, const int & w, const int & h)
{
	m_topleft = tl;
	m_width = w;
	m_height = h;
	return;
}

MyImage::~MyImage()
{
	return;
}
*/

MyCircle::MyCircle(const MyPoint & p, const int & r, const int & lw, const Fl_Color & ec, const Fl_Color & fc)
	:MyShape(lw, ec, fc)
{
	add(p);
	radius = r;
	return;
}

void MyCircle::draw()
{
	fl_line_style(FL_SOLID, m_linewidth);
	fl_color(m_fillcolor);
	fl_pie(Pointset[0].getX(), Pointset[0].getY(), 2 * radius, 2 * radius, 0, 360);
	fl_color(m_edgecolor);
	fl_arc(Pointset[0].getX(), Pointset[0].getY(), 2 * radius, 2 * radius, 0, 360);
}

void MyCircle::redirect(const MyPoint & p, const int & r)
{
	Pointset[0].setXY(p.getX(), p.getY());
	radius = r;
	return;
}

MyCircle::~MyCircle()
{
	return;
}


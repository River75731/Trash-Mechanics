#include "MyShape.h"

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
	fl_line(Pointset.begin()->getX, Pointset.begin()->getY, (Pointset.begin() + 1)->getX, (Pointset.begin() + 1)->getY);
	return;
}

MySegment::~MySegment()
{
	return;
}

MyPolygon::MyPolygon(const std::vector<MyPoint>& ps, const int & lw, const Fl_Color & ec, const Fl_Color & fc)
	:MyShape(lw, ec, fc)
{
	for (std::vector<MyPoint>::iterator i = ps.begin(); i != ps.end(); i++)
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

#include "ViewSegment.h"

ViewSegment::ViewSegment(const ViewSegment & vs)
	:ViewShape(vs.getid(),vs.getvisible())
{
	m_p1 = vs.getp1();
	m_p2 = vs.getp2();
	m_linewidth = vs.getlinewidth();
	m_linecolor = vs.getlinecolor();
}

ViewSegment::ViewSegment(const Segment & s, const int &id, const bool &v, const int & lw, const Fl_Color & lc)
	:ViewShape(id, v)
{
	m_p1 = ViewPoint(s.getV1());
	m_p2 = ViewPoint(s.getV2());
	m_linewidth = lw;
	m_linecolor = lc;
}

ViewSegment::ViewSegment(const ViewPoint & p1, const ViewPoint & p2, const int &id, const bool &v, const int & lw, const Fl_Color & lc)
	:ViewShape(id, v)
{
	m_p1 = p1;
	m_p2 = p2;
	m_linewidth = lw;
	m_linecolor = lc;
}

ViewSegment & ViewSegment::operator=(const ViewSegment & vs)
{
	setSegment(vs.getp1(), vs.getp2(), vs.getlinewidth(), vs.getlinecolor());
	return *this;
}

ViewPoint ViewSegment::getp1() const
{
	return m_p1;
}

ViewPoint ViewSegment::getp2() const
{
	return m_p2;
}

int ViewSegment::getlinewidth() const
{
	return m_linewidth;
}

Fl_Color ViewSegment::getlinecolor() const
{
	return m_linecolor;
}

bool ViewSegment::setp1(const ViewPoint & p1)
{
	m_p1 = p1;
	return true;
}

bool ViewSegment::setp2(const ViewPoint & p2)
{
	m_p2 = p2;
	return true;
}

bool ViewSegment::setlinewidth(const int & lw)
{
	m_linewidth = lw;
	return true;
}

bool ViewSegment::setlinecolor(const Fl_Color & lc)
{
	m_linecolor = lc;
	return true;
}

bool ViewSegment::setSegment(const ViewPoint & p1, const ViewPoint & p2, const int &id, const bool &v, const int & lw, const Fl_Color & lc)
{
	setShape(id, v);
	m_p1 = p1;
	m_p2 = p2;
	m_linewidth = lw;
	m_linecolor = lc;
	return true;
}

bool ViewSegment::setSegment(const Segment & s, const int & id, const bool & v, const int & lw, const Fl_Color & lc)
{
	setShape(id, v);
	m_p1 = ViewPoint(s.getV1());
	m_p2 = ViewPoint(s.getV2());
	m_linewidth = lw;
	m_linecolor = lc;
	return true;
}

bool ViewSegment::setSegment(const Segment & s)
{
	m_p1 = ViewPoint(s.getV1());
	m_p2 = ViewPoint(s.getV2());
	return true;
}

bool ViewSegment::setSegment(const Vec & p1, const Vec & p2)
{
	m_p1 = ViewPoint(p1);
	m_p2 = ViewPoint(p2);
	return true;
}

void ViewSegment::drawShape()
{
	fl_color(m_linecolor);
	fl_line_style(FL_SOLID, m_linewidth);
	fl_line(m_p1.getintX(), m_p1.getintY(), m_p2.getintX(), m_p2.getintY());
}

ViewSegment::~ViewSegment()
{
	return;
}

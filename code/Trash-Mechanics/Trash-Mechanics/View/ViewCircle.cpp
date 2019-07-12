#include "ViewCircle.h"

ViewCircle::ViewCircle(const ViewCircle & vc)
	:ViewShape(vc.getid(), vc.getvisible())
{
	m_center = vc.getcenter();
	m_radius = vc.getradius();
	m_edgewidth = vc.getedgewidth();
	m_edgecolor = vc.getedgecolor();
	m_fillcolor = vc.getfillcolor();
}

ViewCircle::ViewCircle(const ViewPoint & c, const int & r, const int & id, const bool & v, const int & ew, const Fl_Color & ec, const Fl_Color & fc)
	:ViewShape(id, v)
{
	m_center = c;
	m_radius = r;
	m_edgewidth = ew;
	m_edgecolor = ec;
	m_fillcolor = fc;
}

ViewCircle & ViewCircle::operator=(const ViewCircle & vc)
{
	setCircle(vc.getcenter(), vc.getradius(), vc.getid(), vc.getvisible(), vc.getedgewidth(), vc.getedgecolor(), vc.getfillcolor());
	return *this;
}

ViewPoint ViewCircle::getcenter() const
{
	return m_center;
}

int ViewCircle::getradius() const
{
	return m_radius;
}

int ViewCircle::getedgewidth() const
{
	return m_edgewidth;
}

Fl_Color ViewCircle::getedgecolor() const
{
	return m_edgecolor;
}

Fl_Color ViewCircle::getfillcolor() const
{
	return m_fillcolor;
}

bool ViewCircle::setcenter(const ViewPoint & c)
{
	m_center = c;
	return true;
}

bool ViewCircle::setradius(const int & r)
{
	m_radius = r;
	return true;
}

bool ViewCircle::setedgewidth(const int & ew)
{
	m_edgewidth = ew;
	return true;
}

bool ViewCircle::setedgecolor(const Fl_Color & ec)
{
	m_edgecolor = ec;
	return true;
}

bool ViewCircle::setfillcolor(const Fl_Color & fc)
{
	m_fillcolor = fc;
	return true;
}

bool ViewCircle::setCircle(const ViewPoint & c, const int & r, const int & id, const bool & v, const int & ew, const Fl_Color & ec, const Fl_Color & fc)
{
	setShape(id, v);
	m_center = c;
	m_radius = r;
	m_edgewidth = ew;
	m_edgecolor = ec;
	m_fillcolor = fc;
	return true;
}

bool ViewCircle::setCircle(const Vec & p, const int & r, const int & id, const bool & v, const int & ew, const Fl_Color & ec, const Fl_Color & fc)
{
	setShape(id, v);
	m_center = ViewPoint(p);
	m_radius = r;
	m_edgewidth = ew;
	m_edgecolor = ec;
	m_fillcolor = fc;
	return true;
}

bool ViewCircle::setCircle(const Vec & p, const int & r)
{
	m_center = ViewPoint(p);
	m_radius = r;
	return true;
}

bool ViewCircle::setCircle(const Vec & p)
{
	m_center = ViewPoint(p);
	return true;
}

void ViewCircle::drawShape()
{
	fl_color(m_fillcolor);
	fl_pie(m_center.getintX() - m_radius, m_center.getintY() - m_radius, 2 * m_radius, 2 * m_radius, 0, 360);
	fl_color(m_edgecolor);
	fl_line_style(FL_SOLID, m_edgewidth);
	fl_arc(m_center.getintX() - m_radius, m_center.getintY() - m_radius, 2 * m_radius, 2 * m_radius, 0, 360);
}

ViewCircle::~ViewCircle()
{
	return;
}

#include "ViewPolygon.h"

ViewPolygon::ViewPolygon(const ViewPolygon & ps)
	:ViewShape(ps.getid(), ps.getvisible())
{
	m_pointset = ps.getpointset();
	m_edgewidth = ps.getedgewidth();
	m_edgecolor = ps.getedgecolor();
	m_fillcolor = ps.getfillcolor();
}

ViewPolygon::ViewPolygon(const Poly & p, const int &id, const bool &v, const int & ew, const Fl_Color & ec, const Fl_Color & fc)
	:ViewShape(id, v)
{
	m_pointset.clear();
	ViewPoint temp;
	std::vector<Vec> tempvec = p.getPoint();
	for (std::vector<Vec>::const_iterator i = tempvec.begin(); i != tempvec.end(); i++)
	{
		temp = *i;
		m_pointset.push_back(temp);
	}
	m_edgewidth = ew;
	m_edgecolor = ec;
	m_fillcolor = fc;
}

ViewPolygon::ViewPolygon(const std::vector<ViewPoint>& ps, const int &id, const bool &v, const int & ew, const Fl_Color & ec, const Fl_Color & fc)
	:ViewShape(id, v)
{
	m_pointset = ps;
	m_edgewidth = ew;
	m_edgecolor = ec;
	m_fillcolor = fc;
}

ViewPolygon & ViewPolygon::operator=(const ViewPolygon & vp)
{
	setPolygon(vp.getpointset(), vp.getid(), vp.getvisible(), vp.getedgewidth(), vp.getedgecolor(), vp.getfillcolor());
	return *this;
}

std::vector<ViewPoint> ViewPolygon::getpointset() const
{
	return m_pointset;
}

int ViewPolygon::getedgewidth() const
{
	return m_edgewidth;
}

Fl_Color ViewPolygon::getedgecolor() const
{
	return m_edgecolor;
}

Fl_Color ViewPolygon::getfillcolor() const
{
	return m_fillcolor;
}

bool ViewPolygon::setpointset(const std::vector<ViewPoint>& ps)
{
	m_pointset = ps;
	return true;
}

bool ViewPolygon::setedgewidth(const int & ew)
{
	m_edgewidth = ew;
	return true;
}

bool ViewPolygon::setedgecolor(const Fl_Color & ec)
{
	m_edgecolor = ec;
	return true;
}

bool ViewPolygon::setfillcolor(const Fl_Color & fc)
{
	m_fillcolor = fc;
	return true;
}

bool ViewPolygon::setPolygon(const std::vector<ViewPoint>& ps, const int & id, const bool & v, const int & ew, const Fl_Color & ec, const Fl_Color & fc)
{
	setShape(id, v);
	m_pointset = ps;
	m_edgewidth = ew;
	m_edgecolor = ec;
	m_fillcolor = fc;
	return true;
}

bool ViewPolygon::setPolygon(const Poly & p, const int & id, const bool & v, const int & ew, const Fl_Color & ec, const Fl_Color & fc)
{
	setShape(id, v);
	m_pointset.clear();
	ViewPoint temp;
	for (std::vector<Vec>::const_iterator i = p.getPoint().begin(); i != p.getPoint().end(); i++)
	{
		temp = *i;
		m_pointset.push_back(temp);
	}
	m_edgewidth = ew;
	m_edgecolor = ec;
	m_fillcolor = fc;
	return true;
}

bool ViewPolygon::setPolygon(const Poly & p)
{
	m_pointset.clear();
	ViewPoint temp;
	std::vector<Vec> tempvec = p.getPoint();
	for (std::vector<Vec>::const_iterator i = tempvec.begin(); i != tempvec.end(); i++)
	{
		temp = *i;
		m_pointset.push_back(temp);
	}
	return true;
}

bool ViewPolygon::setPolygon(const std::vector<ViewPoint>& ps)
{
	m_pointset = ps;
	return true;
}

void ViewPolygon::drawShape()
{
	fl_color(m_fillcolor);
	fl_begin_polygon();
	for (std::vector<ViewPoint>::iterator i = m_pointset.begin(); i != m_pointset.end(); i++)
		fl_vertex(i->getX(), i->getY());
	fl_end_polygon();
	fl_color(m_edgecolor);
	fl_line_style(FL_SOLID, m_edgewidth);
	for (std::vector<ViewPoint>::iterator i = m_pointset.begin(); i != m_pointset.end() - 1; i++)
		fl_line(i->getintX(), i->getintY(), (i + 1)->getintX(), (i + 1)->getintY());
	fl_line((m_pointset.end() - 1)->getintX(), (m_pointset.end() - 1)->getintY(), (m_pointset.begin())->getintX(), (m_pointset.begin())->getintY());
	return;
}

ViewPolygon::~ViewPolygon()
{
	return;
}

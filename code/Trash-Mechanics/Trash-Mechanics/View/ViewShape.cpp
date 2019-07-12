#include "ViewShape.h"

int ViewShape::m_DEFAULT_LINEWIDTH = DEFAULT_LINEWIDTH;
Fl_Color ViewShape::m_DEFAULT_LINECOLOR = DEFAULT_LINECOLOR;
Fl_Color ViewShape::m_DEFAULT_FILLCOLOR = DEFAULT_FILLCOLOR;
bool ViewShape::m_DEFAULT_VISIBLE = DEFAULT_VISIBLE;

ViewShape::ViewShape(const int & id, const bool & v)
{
	m_id = id;
	m_visible = v;
}

ViewShape & ViewShape::operator=(const ViewShape & vs)
{
	setShape(vs.getid(), vs.getvisible());
	return *this;
}

int ViewShape::getLINEWIDTH()
{
	return m_DEFAULT_LINEWIDTH;
}

Fl_Color ViewShape::getLINECOLOR()
{
	return m_DEFAULT_LINECOLOR;
}

Fl_Color ViewShape::getFILLCOLOR()
{
	return m_DEFAULT_FILLCOLOR;
}

bool ViewShape::getVISIBLE()
{
	return m_DEFAULT_VISIBLE;
}

bool ViewShape::setLINEWIDTH(const int & lw)
{
	m_DEFAULT_LINEWIDTH = lw;
	return true;
}

bool ViewShape::setLINECOLOR(const Fl_Color & lc)
{
	m_DEFAULT_LINECOLOR = lc;
	return true;
}

bool ViewShape::setFILLCOLOR(const Fl_Color & fc)
{
	m_DEFAULT_FILLCOLOR = fc;
	return true;
}

bool ViewShape::setVISIBLE(const bool & v)
{
	m_DEFAULT_VISIBLE = v;
	return true;
}

int ViewShape::getid() const
{
	return m_id;
}

ViewShape::ViewShape(const ViewShape & vs)
{
	m_id = vs.getid();
	m_visible = vs.getvisible();
}

bool ViewShape::setid(const int & id)
{
	m_id = id;
	return true;
}

bool ViewShape::getvisible() const
{
	return m_visible;
}

bool ViewShape::setvisible(const bool & v)
{
	m_visible = v;
	return true;
}

bool ViewShape::setShape(const int & id, const bool & v)
{
	m_id = id;
	m_visible = v;
	return true;
}

bool ViewShape::setShape(const bool & v)
{
	m_visible = v;
	return true;
}

ViewShape::~ViewShape()
{
	return;
}

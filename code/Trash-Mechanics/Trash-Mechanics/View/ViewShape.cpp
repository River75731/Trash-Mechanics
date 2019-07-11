#include "ViewShape.h"

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

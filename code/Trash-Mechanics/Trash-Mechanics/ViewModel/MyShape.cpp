#include "MyShape.h"

Shape::Shape(const int & lw, const Fl_Color & ec, const Fl_Color & fc)
{
	m_linewidth = lw;
	m_edgecolor = ec;
	m_fillcolor = fc;
	return;
}

void Shape::add(const MyPoint & p)
{
	Pointset.push_back(p);
	return;
}

void Shape::move(const int & dx, const int & dy)
{
	for (std::vector<MyPoint>::iterator i = Pointset.begin(); i != Pointset.end(); i++)
	{
		i->setX(i->getX() + dx);
		i->setY(i->getX() + dy);
	}
	return;
}

void Shape::rotate(const int & cx, const int & cy, const double & angle)
{
	for (std::vector<MyPoint>::iterator i = Pointset.begin(); i != Pointset.end(); i++)
	{
	}
	return;
}

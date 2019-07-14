#include "ViewPoint.h"

ViewPoint::ViewPoint():Vec()
{
	return;
}

ViewPoint::ViewPoint(const ViewPoint & vp)
{
	setXY(vp.getX(), vp.getY());
}

ViewPoint::ViewPoint(const Vec & v)
{
	setXY(floor(v.getX()), floor(v.getY()));
}

ViewPoint::ViewPoint(const double & x, const double & y)
{
	setXY(x, y);
}

ViewPoint::ViewPoint(const int & x, const int & y)
{
	setXY(double(x), double(y));
}

ViewPoint & ViewPoint::operator=(const Vec & v)
{
	setXY(v.getX(), v.getY());
	return *this;
}

ViewPoint & ViewPoint::operator=(const ViewPoint & vp)
{
	setXY(vp.getX(), vp.getY());
	return *this;
}

int ViewPoint::getintX() const
{
	return int(getX());
}

int ViewPoint::getintY() const
{
	return int(getY());
}

int ViewPoint::getintMagnitude() const
{
	return int(getMagnitude());
}

ViewPoint::~ViewPoint()
{
	return;
}





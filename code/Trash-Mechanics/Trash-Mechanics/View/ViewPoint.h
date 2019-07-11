#pragma once
#include "..//Common/Common.h"

class ViewPoint : public Vec {
public:
	ViewPoint();
	ViewPoint(const ViewPoint &vp);
	ViewPoint(const Vec &v);
	ViewPoint(const double &x, const double &y);
	ViewPoint(const int &x, const int &y);
	ViewPoint& operator =(const Vec &v);
	ViewPoint& operator =(const ViewPoint &vp);
	int getintX() const;
	int getintY() const;
	int getintMagnitude() const;
	virtual ~ViewPoint();
};
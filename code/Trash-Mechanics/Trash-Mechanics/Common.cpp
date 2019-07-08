#include "Common.h"

Vec::Vec()
{
	m_X = m_Y = 0;
}

Vec::Vec(const double &x, const double &y)
{
	m_X = x;
	m_Y = y;
}

Vec Vec::operator +(const Vec &x) const
{
	Vec t(this->m_X + x.m_X, this->m_Y + x.m_Y);
	return t;
}

Vec Vec::operator -(const Vec &x) const
{
	Vec t(this->m_X - x.m_X, this->m_Y - x.m_Y);
	return t;
}

Vec& Vec::operator +=(const Vec & x)
{
	this->m_X += x.m_X;
	this->m_Y += x.m_Y;
	return (*this);
}

Vec& Vec::operator -=(const Vec & x)
{
	this->m_X -= x.m_X;
	this->m_Y -= x.m_Y;
	return (*this);
}

Vec& Vec::operator =(const Vec &x)
{
	if (this == &x)
		return (*this);
	this->m_X = x.m_X;
	this->m_Y = x.m_Y;
	return (*this);
}

bool Vec::setX(const double &x)
{
	this->m_X = x;
	return true;
}

bool Vec::setY(const double &y)
{
	this->m_Y = y;
	return true;
}

double Vec::getX() const
{
	return this->m_X;
}

double Vec::getY() const
{
	return this->m_Y;
}

double Vec::getAngle() const
{
	return (std::atan2(m_X, m_Y));
}

double Vec::getMagnitude() const
{
	return (sqrt(m_X * m_X + m_Y * m_Y));
}

void Vec::show() const
{
	std::cout << "X " << m_X << " Y " << m_Y << std::endl;
}

bool Vec::setXY(const double &x, const double &y)
{
	this->m_X = x;
	this->m_Y = y;
	return true;
}

Vec::~Vec()
{
	return;
}



bool Poly::setPoly(const Vec &center, const std::vector<Vec> &P)
{
	m_CenterPosition = center;
	m_Point = P;
	m_PointNum = P.size();
	return false;
}
/*
bool Poly::isIntersected(const Segment &s) const
{
	for (std::vector<Vec>::const_iterator i = m_Point.begin(); i != m_Point.end(); i++)
	{
		if (VecToSegmentDist(*i, s) < NearDist)
		{
			return true;
		}	
	}
	return false;
}*/

bool Poly::inPoly(const Vec &v) const
{
	inPoint = false;
	inEdge = false;
	double angleSum = 0.0;
	for (std::vector<Vec>::const_iterator i = m_Point.begin(); i != m_Point.end(); i++)
	{
		Vec v1(*i), v2;
		if (i == m_Point.end() - 1) v2 = *(m_Point.begin());
		else v2 = *(i + 1);
		angleSum += VecAngle(v, v1, v2);
		if (inPoint || inEdge) return true;
		//std::cout << VecAngle(v, v1, v2) << ' ' << angleSum << std::endl;
	}
	if (fabs(angleSum - 2 * pi) < eps) 
		return true;
	return false;
}

double VecToVecDist(const Vec &v1, const Vec &v2)
{
	return ((v1 - v2).getMagnitude());
}

double VecToSegmentDist(const Vec &v, const Segment &s)
{
	Vec v1 = s.getV1();
	Vec v2 = s.getV2();
	double d1 = VecToVecDist(v, v1);
	double d2 = VecToVecDist(v, v2);
	double A = v1.getY() - v2.getY();
	double B = v2.getX() - v1.getX();
	double C = v1.getX() * v2.getY() - v2.getX() * v1.getY();
	double d3 = fabs(A * v.getX() + B * v.getY() + C) / sqrt(A * A + B * B);
	return min(min(d1, d2), d3);
}

double VecAngle(const Vec &v, const Vec &v1, const Vec &v2)
{
	double a = VecToVecDist(v, v1);
	double b = VecToVecDist(v, v2);
	double c = VecToVecDist(v1, v2);
	if (fabs(a) < eps || fabs(b) < eps)
	{
		inPoint = true;
		return 0.0;
	}
	long double x = (a * a + b * b - c * c) / (2 * a * b);
	if (fabs(x - 1) < eps) 
	{
		inEdge = true;
		return 0;
	}
	if (fabs(x + 1) < eps)
	{
		inEdge = true;
		return 0;
	}
	//std::cout << x << std::endl;
	return acos(x);
}
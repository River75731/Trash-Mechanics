#include "Common.h"

bool Vec::setX(double x)
{
	this->m_X = x;
	return true;
}

bool Vec::setY(double y)
{
	this->m_Y = y;
	return true;
}

double Vec::getX()
{
	return this->m_X;
}

double Vec::getX()
{
	return this->m_Y;
}


bool Vec::setXY(double x, double y)
{
	this->m_X = x;
	this->m_Y = y;
	return true;
}
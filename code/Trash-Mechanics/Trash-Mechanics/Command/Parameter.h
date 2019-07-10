#pragma once
#include "..\Common\Common.h"
#include <memory>
#include <Fl_Widget.H>

class Parameter
{
private:

public:
	Parameter(){}
};

class PolyParameter : public Parameter
{
private:
	Poly poly_;
	Fl_Color color_;
public:
	PolyParameter(Poly poly, Fl_Color color = FL_BLACK) :poly_(poly), color_(color){}
	Poly getPoly() const { return poly_; }
	Fl_Color getColor() const { return color_; }
};
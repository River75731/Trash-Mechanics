#pragma once
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <vector>
#include "MyFLTK.h"

class Shape {
private:
	int m_linewidth;
	std::vector <MyPoint> Pointset;
	Fl_Color m_edgecolor,m_fillcolor;
public:
	Shape(const int &lw,const Fl_Color &ec,const Fl_Color &fc);
	void add(const MyPoint &p);
	void move(const int &dx, const int &dy);
	void rotate(const int &cx, const int &cy, const double &angle);
	//virtual void draw();
};
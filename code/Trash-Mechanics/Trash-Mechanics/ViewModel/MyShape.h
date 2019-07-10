#pragma once
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/fl_draw.H>
#include <vector>
#include "MyFLTK.h"

class MyShape {
protected:
	int m_linewidth;
	std::vector <MyPoint> Pointset;
	Fl_Color m_edgecolor,m_fillcolor;
public:
	MyShape(const int &lw,const Fl_Color &ec,const Fl_Color &fc);
	void add(const MyPoint &p);
	virtual ~MyShape();
	virtual void draw();
};

class MySegment : public MyShape {
public:
	MySegment(const MyPoint &p1, const MyPoint &p2, const Fl_Color &lw, const Fl_Color &lc);
	void draw();
	virtual ~MySegment();
};

class MyPolygon : public MyShape {
public:
	MyPolygon(const std::vector<MyPoint> &ps, const int &lw, const Fl_Color &ec, const Fl_Color &fc);
	void draw();
	virtual ~MyPolygon();
};
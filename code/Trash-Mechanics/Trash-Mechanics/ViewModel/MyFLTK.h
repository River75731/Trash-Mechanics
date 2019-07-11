#pragma once
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Double_Window.H>
#include <FL/fl_draw.H>
#include <vector>
#include <string>

class MyPoint
{
private:
	int m_X;
	int m_Y;
public:
	MyPoint();
	MyPoint(const int &x, const int &y);
	int getX() const;
	int getY() const;
	bool setX(const int &x);
	bool setY(const int &y);
	bool setXY(const int &x, const int &y);
	virtual ~MyPoint();
};

class MyShape {
protected:
	int m_linewidth;
	std::vector <MyPoint> Pointset;
	Fl_Color m_edgecolor, m_fillcolor;
public:
	MyShape(const int &lw, const Fl_Color &ec, const Fl_Color &fc);
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
	MyPolygon(const int &lw, const Fl_Color &ec, const Fl_Color &fc);
	MyPolygon(const std::vector<MyPoint> &ps, const int &lw, const Fl_Color &ec, const Fl_Color &fc);
	void draw();
	virtual ~MyPolygon();
};

class MyImage : public MyShape {
public:
	//MyImage(const MyPoint topleft, const )
};

class MyWindow : public Fl_Double_Window
{
private:
	std::vector<MyShape*> Shapeset;
public:
	MyWindow(); 
	MyWindow(MyPoint topleft,const int &width,const int &height,const std::string &name ,const Fl_Color &color);
	void draw();
	void add(MyShape &s);
	virtual ~MyWindow();
};
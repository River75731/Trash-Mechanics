#pragma once
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Double_Window.H>
#include "MyShape.h"
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

class MyWindow : public Fl_Double_Window
{
private:
	std::vector<MyShape> Shapeset;
public:
	MyWindow(); 
	MyWindow(MyPoint topleft,const int &width,const int &height,const std::string &name ,const Fl_Color &color);
	void draw();
	void add(const MyShape &s);
	virtual ~MyWindow();
};
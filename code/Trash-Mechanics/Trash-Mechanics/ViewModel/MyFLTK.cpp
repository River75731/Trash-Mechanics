#include "MyFLTK.h"
#include <string>

MyPoint::MyPoint()
{
	m_X = m_Y = 0;
}

MyPoint::MyPoint(const int &x, const int &y)
{
	m_X = x;
	m_Y = y;
}

int MyPoint::getX() const
{
	return m_X;
}

int MyPoint::getY() const
{
	return m_Y;
}

bool MyPoint::setX(const int &x)
{
	m_X = x;
	return true;
}

bool MyPoint::setY(const int &y)
{
	m_Y = y;
	return true;
}

MyPoint::~MyPoint()
{
	return;
}

MyWindow::MyWindow() :Fl_Double_Window(Fl::w() / 4, Fl::h() / 4, Fl:: w() / 2, Fl:: h() / 2, "New Page")
{
	MyWindow::color(FL_BLACK);
}

MyWindow::MyWindow(MyPoint topleft, const int &width, const int &height, const std::string &name, const Fl_Color &color)
	:Fl_Double_Window(topleft.getX(), topleft.getY(), width, height, name.c_str())
{
	MyWindow::color(color);
}

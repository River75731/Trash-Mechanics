#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Shared_Image.H>
#include <iostream>
#include <vector>
#include "Common/CommonBase.h"
//#include "Others/View-Polygon.h"
//#include "View/MyFLTK.h"
#include "Model/Model.h"
#include "View/GUI.h"

int main(int argc, char *argv[])
{
/*	int w = Fl::w() / 2, h = Fl::h() / 2;
	MyWindow window(MyPoint(w/2,h/2),w,h,"TEST",FL_WHITE);
	MySegment line1(MyPoint(100, 50), MyPoint(300 , 50), 5, FL_BLUE);
	window.add(line1);
	MyPolygon r(5, FL_GREEN, FL_RED);
	r.add(MyPoint(100, 100));
	r.add(MyPoint(100, 200));
	r.add(MyPoint(200, 200));
	fl_register_images();
	Fl_Box        box(0, 0, 1, 1);
	Fl_PNG_Image  png(".//Images//1.png");
	box.image(png);
	Fl_Box box2(100, 100, 101, 101);
	window.show();
	box2.image(png);
	window.show();
	window.add(r);
	MyCircle c1(MyPoint(w, 0), 20, 5, FL_BLUE, FL_RED);
	window.add(c1);
	int x = 300, y = 50, dx = 1, dy = 1;
	int x2 = 400, y2 = 40, dx2 = 3, dy2 = 2;
	while (1)
	{
		x2 += dx2;
		y2 += dy2;
		x += dx;
		y += dy;
		box.resize(x2, y2, 1, 1);
		c1.redirect(MyPoint(x, y), 20);
		if (y2 >= 500||y2<=20) dy2 = -dy2;
		if (x2 >= 800 || x2 <= 20) dx2 = -dx2;
		if (y >= 500 || y <= 20) dy = -dy;
		if (x >= 700 || x <= 20) dx = -dx;
		Fl::check();
		Fl::redraw();
	}
	
	//window.color(FL_RED);
	/*Fl_Window     win(720, 486);
	fl_register_images();
	win.show();
	//MyWindow win;
	Fl_Box        box(0,0,400,400);
	Fl_PNG_Image  png(".//Images//1.png");
	box.image(png);
	win.redraw();
	win.show();
	win.resize(50, 100, 400, 400);*/


	ViewWindow window(400,100,800,500,"NNN Page",FL_WHITE);
	ViewSegment line1(ViewPoint(100, 50), ViewPoint(300, 50), 1, 1, 5);
	ViewCircle c1(ViewPoint(200, 100), 20, 2, 1, 3, FL_BLUE, FL_RED);
	ViewPolygon p1({ ViewPoint(100,100),ViewPoint(100,200),ViewPoint(200,200) }, 3);
	window.attach(line1);
	window.attach(c1);
	window.attach(p1);
	window.show();
	window.setcolor(FL_YELLOW);
	int x = 300, y = 50, dx = 1, dy = 1;
	while (1)
	{
		x += dx;
		y += dy;
		if (y >= 500 || y <= 20) dy = -dy;
		if (x >= 800 || x <= 20) dx = -dx;
		c1.setCircle(ViewPoint(x,y));
		Fl::check();
		Fl::redraw();
	}
		return Fl::run();
}

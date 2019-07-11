#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Shared_Image.H>
#include <iostream>
#include <vector>
#include "Common/Common.h"
#include "Others/View-Polygon.h"
#include "ViewModel/MyFLTK.h"
#include "Model/Model.h"
int main(int argc, char *argv[])
{
	int w = Fl::w() / 2, h = Fl::h() / 2;
	MyWindow window(MyPoint(w/2,h/2),w,h,"TEST",FL_WHITE);
	MySegment line1(MyPoint(100, 50), MyPoint(300 , 50), 5, FL_BLUE);
	window.add(line1);
	MyPolygon r(5, FL_GREEN, FL_RED);
	r.add(MyPoint(100, 100));
	r.add(MyPoint(100, 200));
	r.add(MyPoint(200, 200));
	fl_register_images();
	Fl_Box        box(10, 10, 11, 11);
	Fl_PNG_Image  png(".//Images//1.png");
	box.image(png);
	Fl_Box box2(100, 100, 101, 101);
	window.show();
	box2.image(png);
	window.show();
	window.add(r);
	int x = 300, y = 50, dx = 1, dy = 1;
	while (1)
	{
		x += dx;
		y += dy;
		box.resize(x, y, 1, 1);
		if (y >= 500) dy = -1;
		if (y <= 20) dy = 1;
		if (x >= 700) dx = -1;
		if (x <= 20) dx = 1;
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
		return Fl::run();
}
/*
int main()
{
	int w = Fl::w() / 2, h = Fl::h() / 2;

	Fl_Window *window = new Fl_Window(800, 600);

	Poly pa = Poly(Vec(100, 70), std::vector<Vec>{Vec(50, 50), Vec(150, 50), Vec(150, 150)});

	Poly pb = Poly(Vec(180, 180), std::vector<Vec>{Vec(100, 140), Vec(200, 140), Vec(200, 200), Vec(100, 200)});

	pa.inPoly_PolyVec(pb);

	pa.getInterPoint(pb);

	pa.getInterSegment(pb);

	//b.collide(a);

	window->show();

	return Fl::run();
}*/

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
		//box.hide();
	window.show();
	window.add(r);
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
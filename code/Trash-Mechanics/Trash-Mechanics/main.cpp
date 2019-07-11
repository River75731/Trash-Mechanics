#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <Fl_PNG_Image.H>
#include <Fl_Shared_Image.H>
#include <iostream>
#include <vector>
#include "Common/Common.h"
#include "Others/View-Polygon.h"
#include "ViewModel/MyFLTK.h"
#include "Model/Model.h"

int main(int argc, char *argv[])
{
	/*int w = Fl::w() / 2, h = Fl::h() / 2;
	MyWindow window(MyPoint(w/2,h/2),w,h,"TEST",FL_WHITE);
	MySegment line1(MyPoint(100, 50), MyPoint(300 , 50), 5, FL_BLUE);
	window.add(line1);
	MyPolygon r(5, FL_GREEN, FL_RED);
	r.add(MyPoint(100, 100));
	r.add(MyPoint(100, 200));
	r.add(MyPoint(200, 200));
	window.add(r);
	window.show();*/
		fl_register_images();
		int x=600, y = 10;
		MyWindow* a = new MyWindow();
		Fl_Box        box(10, 10, 11, 11);
		Fl_Box box2(100, 100, 101, 101);
		Fl_PNG_Image  png(".//Images//1.png");
		a->show();
		box.image(png);
		box2.image(png);
		int dx = 0, dy = 1;
		while (1)
		{
			x += dx, y += dy;
			box.resize(x, y, 1, 1);
			if (y >= 500) dy = -1;
			if (y <= 10)dy = 1;
			a->redraw();
		}
		return Fl::run();
}
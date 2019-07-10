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
	MyWindow *window = new MyWindow();
	MySegment line1(MyPoint(100, 50), MyPoint(300 , 50), 5, FL_RED);
	window->add(line1);
	fl_color(FL_RED);
	fl_line_style(FL_SOLID, 100);
	fl_line(Fl::w()/4, Fl::h()/2, Fl::w()*3/4, Fl::h()/2);
	window->show();

		/*fl_register_images();
		MyWindow* a = new MyWindow();
		Fl_Box        box(10, 10, 11, 11);
		Fl_Box box2(100, 100, 101, 101);
		Fl_PNG_Image  png(".//Images//1.png");
		box.image(png);
		box2.image(png);
		a->show();
		box.hide();
		a->color(FL_RED);
		a->show();*/
		return(Fl::run());
}